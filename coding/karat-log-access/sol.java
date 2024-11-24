import java.util.*;

public class LogAnalyzer {

    public static Map<String, List<Integer>> getSortedAccessTimes(List<List<String>> logs) {
        Map<String, List<Integer>> accessTimes = new HashMap<>();

        for (List<String> log : logs) {
            String user = log.get(1);
            int num = Integer.parseInt(log.get(0));

            if (accessTimes.containsKey(user)) {
                List<Integer> times = accessTimes.get(user);
                if (times.get(0) > num) {
                    times.set(0, num);
                } else if (times.get(1) < num) {
                    times.set(1, num);
                }
            } else {
                accessTimes.put(user, new ArrayList<>(Arrays.asList(num, num)));
            }
        }
        return accessTimes;
    }

    public static List<String> getMostAccessedResource(List<List<String>> logs) {
        Map<String, List<Integer>> accessTimes = new HashMap<>();
        int max = 0;
        String resourceMax = "";

        for (List<String> log : logs) {
            String resource = log.get(2);
            int num = Integer.parseInt(log.get(0));

            accessTimes.putIfAbsent(resource, new ArrayList<>());
            List<Integer> times = accessTimes.get(resource);

            while (!times.isEmpty() && times.get(0) < num - 300) {
                times.remove(0);
            }
            times.add(num);

            if (times.size() > max) {
                max = times.size();
                resourceMax = resource;
            }
        }

        return Arrays.asList(resourceMax, String.valueOf(max));
    }

    public static void printSolution(Map<String, List<Integer>> accessTimes) {
        for (Map.Entry<String, List<Integer>> entry : accessTimes.entrySet()) {
            System.out.println(entry.getKey() + " " + entry.getValue().get(0) + "," + entry.getValue().get(1));
        }
    }

    public static void main(String[] args) {
        List<List<String>> logs1 = Arrays.asList(
            Arrays.asList("2", "user_1", "resource_1"),
            Arrays.asList("3234", "user_2", "resource_2"),
            Arrays.asList("456", "user_1", "resource_3"),
            Arrays.asList("200", "user_6", "resource_5"),
            Arrays.asList("215", "user_6", "resource_4"),
            Arrays.asList("43553", "user_2", "resource_3"),
            Arrays.asList("63346", "user_3", "resource_3"),
            Arrays.asList("35445", "user_22", "resource_1"),
            Arrays.asList("5345", "user_5", "resource_3"),
            Arrays.asList("2", "user_6", "resource_1"),
            Arrays.asList("100", "user_6", "resource_6"),
            Arrays.asList("400", "user_7", "resource_2"),
            Arrays.asList("100", "user_8", "resource_6"),
            Arrays.asList("5534", "user_1", "resource_3")
        );

        List<List<String>> logs2 = Arrays.asList(
            Arrays.asList("300", "user_1", "resource_3"),
            Arrays.asList("599", "user_1", "resource_3"),
            Arrays.asList("900", "user_1", "resource_3"),
            Arrays.asList("1199", "user_1", "resource_3"),
            Arrays.asList("1200", "user_1", "resource_3"),
            Arrays.asList("1201", "user_1", "resource_3"),
            Arrays.asList("1202", "user_1", "resource_3")
        );

        List<List<String>> logs3 = Arrays.asList(
            Arrays.asList("300", "user_10", "resource_5")
        );

        printSolution(getSortedAccessTimes(logs1));
        List<String> res = getMostAccessedResource(logs1);
        System.out.println(res.get(0) + " : " + res.get(1));

        // Uncomment to test other logs
        // printSolution(getSortedAccessTimes(logs2));
        // printSolution(getSortedAccessTimes(logs3));
    }
}
