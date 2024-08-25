// 按两次 Shift 打开“随处搜索”对话框并输入 `show whitespaces`，
// 然后按 Enter 键。现在，您可以在代码中看到空格字符。
public class Shape2DApp {
    public static void main(String[] args) {
        Shape[] shapes = new Shape[3];
        shapes[0] = new Circle(10);
        shapes[1]=new Triangle(25,10);
        shapes[2]=new Rectangle(50,20);
        double totalArea=0;
        for(Shape shape:shapes){
            totalArea+=shape.getArea();
        }
        System.out.println("Total area: "+totalArea);
    }
}