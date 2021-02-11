package edu.corellj.Assign06;

import edu.corellj.Assign05.CharImage;
public class Troll extends Creature {
    public Troll(){

    }

    public Troll(int row, int col){
        super(row, col);
    }

    public String toString(){
        return "Troll at " + getRow() + "," + getCol();
    }

    public void draw(CharImage map){
        map.setPos(getRow(), getCol(), 'T');
    }
}
