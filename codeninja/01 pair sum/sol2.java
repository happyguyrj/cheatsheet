import java.util.*;

public class HelloWorld{

    public static int[][] pairSum(int arr[], int s) {
        int n = arr.length;

        // HashMap to store frequency of elements.
        HashMap<Integer, Integer> map = new HashMap();

        // This will store the result.
        List<int[]> ans = new ArrayList();
        for (int ele : arr) {
            int count = map.getOrDefault(s - ele, 0);

            int[] pair = new int[2];
            pair[0] = ele;
            pair[1] = s - ele;

            while (count-- > 0) {
                ans.add(pair);
            }

            map.put(ele, map.getOrDefault(ele, 0) + 1);
        }

        // This will to store final result.
        int res[][] = new int[ans.size()][2];

        // Sorting the 'ans' arrays element.
        for (int i = 0; i < ans.size(); i++) {
            int a = ans.get(i)[0], b = ans.get(i)[1];
            res[i][0] = Math.min(a, b);
            res[i][1] = Math.max(a, b);
        }

        // Finally sorting each pair in 'res'.
        Arrays.sort(res, new Comparator<int[]>() {
            public int compare(int[] a, int[] b) {
                if (a[0] == b[0]) {
                    return a[1] - b[1];
                }
                return a[0] - b[0];
            }
        });

        return res;
    }

    public static void main(String []args){
        int[] arr;

        arr = new int[5];
        arr[0] = 10;
        arr[1] = 20;
        arr[2] = 30;
        arr[3] = 40;
        arr[4] = 50;

        int[][] res = pairSum(arr, 50);

        for (int i = 0; i < res.length; i++){
            for (int j = 0; j < res[i].length; j++)
                System.out.print(res[i][j] + " ");
            System.out.println(" ");
        }

        return;
     }
}