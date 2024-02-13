public class Rectangle implements Shape{
    private double width,height;
    public Rectangle(double width, double height){
        this.width=width;
        this.height=height;
    }
    public double getArea(){
        return width*height;
    }
}
