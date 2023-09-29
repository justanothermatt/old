/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package rectangleviewer;

import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Rectangle;
import javax.swing.JComponent;
/**
 *
 * @author Matt Walker
 */
public class RectangleComponent extends JComponent {
    public void paintComponent(Graphics g){
        // Recover Graphics 2D
        Graphics2D g2 = (Graphics2D) g;
        
        // Construct and draw a rectangle
        Rectangle box = new Rectangle(5,10,20,30);
        g2.draw(box);
        
        // Move rectangle 15 pixles to the right and 25 pixles down
        box.translate(15,25);
        
        //Draw moved rectangle
        g2.draw(box);
    }
}
