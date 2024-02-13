public class Cubiod implements Shape3D{
    private double width,height,depth;
    public Cubiod(double width, double height, double depth){
        this.width=width;
        this.height=height;
        this.depth=depth;
    }
    public double getVolume(){
        return width*height*depth;
    }
    public double getArea(){
        return 2*(width*height+height*depth+depth*width);
    }
}
