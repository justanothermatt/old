/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package foo;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.Point;

/**
 *
 * @author Matt Walker
 */
public abstract class DrawItem {
    
    public static final int FREEHAND         = 0;
    public static final int LINE             = 1;
    public static final int OPEN_RECTANGLE   = 2;
    public static final int FILLED_RECTANGLE = 3;
    public static final int STAR             = 4;
    public static final int CIRCLE           = 5;
    
    Point itemLocation;
    Color itemColor;
    
    DrawItem(Point itemLocation, Color itemColor){
        this.itemLocation = itemLocation;
        this.itemColor = itemColor;
    }
    
    public Point   getItemLocation(){
        return itemLocation;
    }
    public void    setItemLocation(Point Location){
        this.itemLocation = Location;
    }
    public Color   getItemColor(){
        return itemColor;
    }
    public void    setItemColor(Color color){
        this.itemColor = color;
    }
    
    public abstract void draw(Graphics g);
    public abstract void add(Point p);
    
}

