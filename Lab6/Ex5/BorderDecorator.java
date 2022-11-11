package Ex5;
import java.awt.*;

public class BorderDecorator extends Decorator{

    public BorderDecorator(Component t, int x, int y, int width, int height){
        super(t);
        this.x = x;
        this.y = y;
        this.width = width;
        this.height =height;
    }

    @Override
    public void draw(Graphics g) {
        cmp.draw(g);
        Graphics2D g2d = (Graphics2D) g;
        Stroke stroke = new BasicStroke(3, BasicStroke.CAP_BUTT, BasicStroke.JOIN_BEVEL, 0, new float[]{9}, 0);
        
        g2d.setStroke(stroke);
        g2d.setColor(Color.black);
        g2d.drawRect(x, y, width, height);
    }
}
