public class Cylinder implements Shape3D{
    private double radius,height;
    public Cylinder(double radius, double height){
        this.radius=radius;
        this.height=height;
    }
    public double getVolume(){
        return Math.PI*radius*radius*height;
    }
    public double getArea(){
        return 2*Math.PI*radius*height+2*Math.PI*radius*radius;
    }
}
