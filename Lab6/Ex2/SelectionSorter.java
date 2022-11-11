package Ex2;

import java.util.ArrayList;

public class SelectionSorter <E extends Number & Comparable<E>> implements Sorter<E>{
    
    @Override
    public void sort(ArrayList<Item<E>> arr) {
        int n = arr.size();
        for (int i = 1; i < n-1; i++) {
            int min_val = i;
            for (int j = i+1; j < n; j++) {
                if (arr.get(j).getItem().compareTo(arr.get(min_val).getItem()) < 0){
                    min_val = j;
                }
            }
            Item<E> temp = arr.get(i);
            arr.set(min_val, arr.get(i));
            arr.set(i, temp);
        }
    }
}