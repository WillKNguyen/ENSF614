package Ex2;

import java.util.ArrayList;

public class BubbleSorter<E extends Number & Comparable<E>> implements Sorter<E>{
    
    @Override
    public void sort(ArrayList<Item<E>> arr) {
        int n = arr.size();
        for (int i = 0; i < n-1; i++) {
            for (int j = 0; j < n-i-1; j++) {
                E value1 = arr.get(j).getItem();
                E value2 = arr.get(j+1).getItem();
                if (value1.compareTo(value2) > 0){
                    Item<E> temp = arr.get(j);
                    arr.set(j, arr.get(j+1));
                    arr.set(j+1, temp);
                }
            }
        }
    }
}
