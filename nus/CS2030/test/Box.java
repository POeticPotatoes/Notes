@FunctionalInterface
interface F<T, R> {
    R run(T x);
}

class Box<T> {
    private T x;

    public Box(T x) {
        this.x = x;
    }

    public T get() {
        return x;
    }
}
