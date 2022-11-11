package Ex5;

import java.awt.*;

public class ColouredFrameDecorator extends Decorator{
    private int thickness;

    public ColouredFrameDecorator(Component t, int x, int y, int width, int height, int thickness){
        super(t);
        this.x = x;
        this.y = y;
        this.width = width;
        this.height =height;
        this.thickness = thickness;
    }
    
    @Override
    public void draw(Graphics g) {
        // TODO Auto-generated method stub
        cmp.draw(g);
        Graphics2D g2d = (Graphics2D) g;
        g2d.setStroke(new BasicStroke(thickness));
        g2d.setColor(Color.red);
        g2d.drawRect(x, y, width, height);
    }
}
