package Ex5;

import java.awt.Graphics;

public class Text implements Component{
    private String text;
    private int x;
    private int y;

    public Text(String str, int x, int y){
        text=str;
        this.x=x;
        this.y=y;
    }

    @Override
    public void draw(Graphics g) {
        g.drawString(text,x,y);
    }
}
