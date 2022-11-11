package Ex2;

import java.util.ArrayList;

interface Sorter<E extends Number & Comparable<E>> {
    public void sort(ArrayList<Item<E>> arr);
}
