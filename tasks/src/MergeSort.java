import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Scanner;

public class MergeSort {
    public static void main(String[] args)
    {
        //int[] A = new int[10];
        ArrayList<Integer> arr = new ArrayList<>(10);
        Scanner sc = new Scanner(System.in);
        while(sc.hasNextInt())
        {
            arr.add(sc.nextInt());
        }
        mSort(arr, 0, arr.size() - 1);
        for(int i = 0; i < arr.size(); i++)
            System.out.format("%d ", arr.get(i));
    }
    private static void merge(ArrayList<Integer> arr, int left, int right, int m)
    {
        ArrayList<Integer> L = new ArrayList<>(m - left + 1);
        for(int i = 0; i < m - left + 1; i++)
            L.add(i, arr.get(left + i));
        ArrayList<Integer> R = new ArrayList<>(right - m);
        for(int i = 0; i < right - m; i++) {
            //System.out.format("left: %d, m: %d, i: %d\n", left, m, i);
            R.add(i, arr.get(m + i + 1));
        }

        int i = 0, j = 0, k = left;
        while (i < m - left + 1 && j < right - m) //m-left+1?
        {
            if(L.get(i) <= R.get(j))
            {
                arr.set(k,  L.get(i));
                i++;
            }
            else
            {
                arr.set(k, R.get(j));
                j++;
            }
            k++;
        }
        while(i < m - left + 1)
        {
            arr.set(k, L.get(i));
            i++;
            k++;
        }
        while(j < right - m)
        {
            arr.set(k, R.get(j));
            j++;
            k++;
        }
    }
    private static void mSort(ArrayList<Integer> arr, int left, int right)
    {
        if(left < right) {
            int m = left + (right - left) / 2;
            mSort(arr, left, m);
            mSort(arr, m + 1, right);
            merge(arr, left, right, m);
        }
    }
}
