public class Shape3DApp {
    public static void main(String[] args) {
        Shape3D[] shapes= new Shape3D[3];
        shapes[0]=new Sphere(10);
        shapes[1]=new Pyramid(25,10);
        shapes[2]=new Cubiod(50,20,30);
        double totalArea=0;
        double totalVolume=0;
        for(Shape3D shape:shapes){
            totalArea+=shape.getArea();
            totalVolume+=shape.getVolume();
        }
        System.out.println("Total area: "+totalArea);
        System.out.println("Total volume: "+totalVolume);
    }
}
