package Ex4;

import java.util.ArrayList;

public class OneRow_Observer implements Observer{
    private DoubleArrayListSubject data;
    private ArrayList<Double> arr;
    
    public OneRow_Observer(DoubleArrayListSubject data){
        this.data = data;
        data.register(this);
    }

    @Override
    public void update(ArrayList<Double> arr) {
        this.arr = arr;
        display(); 
    }

    public void display() {
        StringBuilder str = new StringBuilder();
        str.append("\nNotification to One-Row Table Observer: Data Changed:\n");
        for (int i = 0; i < arr.size(); i++) {
            str.append(arr.get(i)).append(' ');
        }
        System.out.println(str);
    }
}
