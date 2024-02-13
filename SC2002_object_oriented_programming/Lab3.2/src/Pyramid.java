public class Pyramid implements Shape3D{
    private double height,length;
    public Pyramid(double height,double length){
        this.height=height;
        this.length=length;
    }
    public double getVolume(){
        return length*length*height/3;
    }
    public double getArea(){
        return length*length+2*length*Math.sqrt(length*length/4+height*height);
    }
}
