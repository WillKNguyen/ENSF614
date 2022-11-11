package Ex2;

import java.util.ArrayList;

public class MyVector<E extends Number & Comparable<E>> {
    private ArrayList<Item<E>> storageM;
    private Sorter<E> sorter;

    public MyVector(int n){
        storageM = new ArrayList<Item<E>>(n);
    }

    public MyVector(ArrayList<Item<E>> arr){
        storageM = new ArrayList<Item<E>>(arr.size());
        for (int i= 0; i < arr.size(); i++){
            storageM.get(i).setItem(arr.get(i).getItem());
        }
    }

    public void add(Item<E> value){
        storageM.add(value);
    }

    public void setSortStrategy(Sorter<E> s){
        sorter = s;
    }

    public void performSort(){
        sorter.sort(storageM);
    }

    public void display(){
        StringBuilder str = new StringBuilder();
        for (int i = 0; i < storageM.size(); i++) {
            str.append(storageM.get(i).getItem()).append(' ');
        }
        System.out.println(str);
    }
}
