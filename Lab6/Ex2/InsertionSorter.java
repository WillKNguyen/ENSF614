package Ex2;

import java.util.ArrayList;

public class InsertionSorter<E extends Number & Comparable<E>> implements Sorter<E>{
    
    @Override
    public void sort(ArrayList<Item<E>> arr) {
        int n = arr.size();
        for (int i = 1; i < n; i++) {
            E key = arr.get(i).getItem();
            int j = i -1;
            while (j>=0 && arr.get(j).getItem().compareTo(key) > 0){
                // arr.set(j+1, arr.get(j));
                arr.get(j+1).setItem(arr.get(j).getItem());
                j = j - 1;
            }
            // arr.set(j+1, arr.get(i));
            arr.get(j+1).setItem(key);
        }
    }
}
    
