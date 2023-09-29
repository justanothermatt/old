/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package foo;
import java.awt.*;
import java.util.*;

/**
 *
 * @author Matt Walker
 */
public class Freehand extends DrawItem{
    private java.util.List dots = new ArrayList();
    
    public Freehand(Point thisPoint, Color thisColor){
        super(thisPoint, thisColor);
        dots.add(thisPoint);
    }
    
    public void add(Point thisPoint){
        dots.add(thisPoint);
    }
    
    public void draw(Graphics g){
        Iterator setOfPoints = dots.iterator();
        Point lastPoint = null;
        while(setOfPoints.hasNext()){
            Point thisPoint = (Point) setOfPoints.next();
            if(lastPoint != null){
                g.drawLine(lastPoint.x, lastPoint.y, thisPoint.x, thisPoint.y);
            }
            lastPoint = thisPoint;
        }
    }
}
