
import java.util.*;


public class HelloWorld{

    public static int[][] pairSum(int arr[], int s) {
         // Used to store result.
		List<int[]> ans = new ArrayList();
		HashMap<Integer, Integer> map = new HashMap<>();

		for (int num : arr) {
			map.put(num, map.getOrDefault(num, 0) + 1);
		}

		Integer[] keyArray = map.keySet().toArray(new Integer[map.keySet().size()]);

		Arrays.sort(keyArray);
		for (int key : keyArray) {
			if (key + key == s) {
				int freq = map.get(key);
				for (int j = 0; j < freq * (freq - 1) / 2; j++) {
					ans.add(new int[] { key, key });
				}
			}
		}

		int low = 0;
		int high = keyArray.length - 1;

		while (low < high) {
			int currSum = keyArray[low] + keyArray[high];
			if (currSum == s) {
				int freq = map.get(keyArray[low]) * map.get(keyArray[high]);
				for (int j = 0; j < freq; j++) {
					ans.add(new int[] { keyArray[low], keyArray[high] });
				}
				low++;
				high--;
			}
			else if (currSum < s)
				low++;
			else
				high--;
		}

		int res[][] = new int[ans.size()][2];
		for (int i = 0; i < ans.size(); i++) {
			int a = ans.get(i)[0], b = ans.get(i)[1];
			res[i][0] = Math.min(a, b);
			res[i][1] = Math.max(a, b);
		}

		Arrays.sort(res, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				if (a[0] == b[0])
					return a[1] - b[1];

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