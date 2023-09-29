/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package menupackage;

import java.io.*;

/**
 *
 * @author ID139
 */
public class TextFileFilter extends javax.swing.filechooser.FileFilter{
    
    // To filter files based on their file type, place the extension in
    // the list of extensions below.
    private final static String[] EXTENSIONS = { ".html", ".java", ".txt" }; 
    
    // null constructor
    public TextFileFilter(){}
    
    // accept: inherited as an abstract method, so it needs to be defined -
    // method is automatically called by JFileChooser to filter the files
     // that it encounters within a directory.
    // Returns true if the file should be displayed.
    public boolean accept( File f ) {
            
     // directories should always be allowed...
     if ( f.isDirectory() ) return true;

     // iterate through the list of extensions - if a match is found
     // then return true to accept the displaying of this file.
    for ( String extension : EXTENSIONS ) {
        if ( f.getName().toLowerCase().endsWith( extension ) ) return true;
    }

    // if here, then no match, so don't show the file in the chooser.
        return false;
 }
 
    // getDescription: the description of this filter.
 
    @Override
    public String getDescription() {
    StringBuffer filetypes = new StringBuffer();
    for ( String extension : EXTENSIONS )
     filetypes.append( extension + " " );
    return filetypes.toString();
 } 
}
