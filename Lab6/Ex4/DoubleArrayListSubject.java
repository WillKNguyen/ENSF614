package Ex4;

import java.util.ArrayList;

public class DoubleArrayListSubject {
    private ArrayList<Double> data;
    private ArrayList<Observer> observers;

    public DoubleArrayListSubject(){
        data = new ArrayList<>();
        observers = new ArrayList<>();
    }

    public void addData(double x) {
        data.add(x);
        notifyObserver();
    }

    public void setData(double x, int i) {
        data.set(i, x);    
        notifyObserver();  
    }

    public void populate(double[] arr) {
        for (int i = 0; i < arr.length; i++) {
            addData(arr[i]);
        }
        notifyObserver();
    }

    public void display() {
        System.out.println("Empty List ...");
    }

    public void register(Observer o) {
        observers.add(o);
        o.update(data);
    }

    public void remove(Observer o) {
        observers.remove(o);
    }

    public void notifyObserver() {
        for (int i = 0; i < observers.size(); i++) {
            Observer o = observers.get(i);
            o.update(data);
        }
    }
}
