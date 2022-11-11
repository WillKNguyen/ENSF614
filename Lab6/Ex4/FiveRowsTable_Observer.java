package Ex4;

import java.util.ArrayList;

public class FiveRowsTable_Observer implements Observer{
    private DoubleArrayListSubject data;
    private ArrayList<Double> arr;
    
    public FiveRowsTable_Observer(DoubleArrayListSubject data){
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
        str.append("\nNotification to Five-Rows Table Observer: Data Changed:\n");
        for (int i = 0; i < Math.min(arr.size(), 5); i++) {
            for (int j = i; j<arr.size(); j +=5){
                str.append(arr.get(j)).append(' ');
            }
            if ((i+1)/5 != 1)
                str.append("\n");
        }
        System.out.println(str);
    }
}
