/*
You with few of your friends decide to go for a movie and take their own cars. The theater has a linear parking spot with some cars already parked.
You guys want to park your car as close as possible. Find the min distance between the cars that is possible.

Parking spot availability is represented as an array where 1 denotes occupied and 0 is free.

Example [0, 1, 0, 0, 1, 1, 0]
No of friends - 3

Output : 3

*/
import java.util.*;

class Main {
    public static void main(String[] args) {
        int[] slots = {0,1,0,0,1,1,0,0,0};
        // int[] slots = {1,1,1,1,0,0,0};

        System.out.println(getMinimumDistance(slots,3));

        return;
    }

    private static int getMinimumDistance(int[] slots, int numFriends) {
        int firstCar = -1;
        List<Integer> carPositions = new ArrayList<>();

        for(int i=0; i<slots.length; i++){
            if (slots[i] == 0) {
                firstCar = i;
                numFriends--;
                carPositions.add(i);
                break;
            }
        }

        if(firstCar == -1) {
            return -1;
        }

        if(numFriends == 0) {
            return 0;
        }

        int lastCar=-1;
        for(int i=firstCar+1;  i<slots.length && numFriends>0; i++){
            if (slots[i] == 0) {
                lastCar = i;
                numFriends--;
                carPositions.add(i);
            }
        }

        if(numFriends > 0) {
            return -1;
        }

        int minDistance = lastCar - firstCar;
        int startCars = 1;

        for(int i=lastCar+1;  i<slots.length; i++){
            if (slots[i] == 0) {
                lastCar = i;
                carPositions.add(i);
                firstCar = carPositions.get(startCars++);
                if(lastCar-firstCar < minDistance) {
                    minDistance = lastCar-firstCar;
                }
            }
        }
        return minDistance;
    }
}