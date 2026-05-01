import java.io.*;
import java.util.*;

public class Main {
    public static void nextGreaterWithStack(int[] arr) {
        int n = arr.length;
        Stack<Integer> stack = new Stack<>();

        stack.push(arr[0]);

        for (int i = 1; i < n; i++) {
            int next = arr[i];

            while (!stack.isEmpty() && stack.peek() < next) {
                System.out.println(stack.pop() + " -> " + next);
            }

            stack.push(next);
        }

        while (!stack.isEmpty()) {
            System.out.println(stack.pop() + " -> -1");
        }
    }

    public static int[] nextGreaterElement(int[] arr) {
        int n = arr.length;
        int[] nextgr = new int[n];
        Arrays.fill(nextgr, n); // default: no greater element

        // Build next greater index using pointer jumping
        for (int i = n - 2; i >= 0; i--) {
            int ans = i + 1;

            while (ans < n && arr[ans] <= arr[i]) {
                ans = nextgr[ans]; // jump forward
            }

            nextgr[i] = ans;
        }

        // Convert indices to values
        int[] res = new int[n];
        for (int i = 0; i < n; i++) {
            res[i] = (nextgr[i] == n) ? -1 : arr[nextgr[i]];
        }

        return res;
    }
    
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine().trim());
        int[] arr = new int[n];

        String[] input = br.readLine().trim().split(" ");
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(input[i]);
        }

        int[] res = nextGreaterElement(arr);

        for (int i = 0; i < n; i++) {
            System.out.println(arr[i] + " -> " + res[i]);
        }
    }
}