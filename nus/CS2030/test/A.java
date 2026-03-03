import java.util.stream.Stream;

public class A {
    public static void main(String[] args) {
        long res = Stream
            .iterate(1, x -> x+1)
            .limit(5)
            .map(i -> Stream.iterate(1, x -> x <= i, x -> x + 1))
            .filter(x -> x.count() % 2 == 0)
            .flatMap(x -> x)
            .count();
        System.out.println(res);
    }
}
