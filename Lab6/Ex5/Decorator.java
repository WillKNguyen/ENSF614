package Ex5;

public abstract class Decorator implements Component{
    protected Component cmp;
    protected int x;
    protected int y;
    protected int width;
    public int height;

    public Decorator(Component t){
        this.cmp=t;
    }
}
