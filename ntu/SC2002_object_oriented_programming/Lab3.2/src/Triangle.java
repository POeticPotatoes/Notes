public class Triangle implements Shape {
    private double height,base;
    public Triangle(double height, double base){
        this.height=height;
        this.base=base;
    }
    public double getArea(){
        return height*base/2;
    }

}
