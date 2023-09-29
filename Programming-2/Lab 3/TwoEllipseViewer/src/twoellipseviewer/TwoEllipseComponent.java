/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package twoellipseviewer;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.geom.Ellipse2D;
import javax.swing.JComponent;
/**
 *
 * @author ID139
 */
public class TwoEllipseComponent extends JComponent{
    public void paintComponent(Graphics g){
        
        Graphics2D g2 = (Graphics2D) g;
        Ellipse2D e1 = new Ellipse2D.Double(20,20,100,50);
        g.setColor(Color.PINK);
        g2.fill(e1);
        Ellipse2D e2 = new Ellipse2D.Double(100,150,100,50);
        Color Purple = new Color(148,0,211);
        g.setColor(Purple);
        g2.fill(e2);
        
        
    }
}
