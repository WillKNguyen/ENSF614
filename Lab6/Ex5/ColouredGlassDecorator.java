package Ex5;
import java.awt.*;

public class ColouredGlassDecorator extends Decorator{
    public ColouredGlassDecorator(Component t, int x, int y, int width, int height){
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
        g2d.setColor(Color.GREEN);
        g2d.setComposite(AlphaComposite.getInstance(AlphaComposite.SRC_OVER, 1 * 0.1f));
        g2d.fillRect(25, 25, 110, 110);
    }
}
