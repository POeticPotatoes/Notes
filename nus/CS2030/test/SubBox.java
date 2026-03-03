class SubBox<T> extends Box<T> {
    public static void main(String[] args) {
    }

    public SubBox(T x) {
        super(x);
    }

    public static <T> SubBox<T> of (int x) {
        @SuppressWarnings("unchecked")
        SubBox<T> box = (SubBox<T>) new IntBox(x);
        return box;
    }

    public <U> SubBox<T> merge(F<SubBox<U>, T> f, SubBox<U> other) {
        return this;
    }

    private static class IntBox extends SubBox<Integer> {
        public IntBox(Integer x) {
            super(x);
        }

        @Override
        public <U> IntBox merge(F<SubBox<U>, Integer> f, SubBox<U> other) {
            return new IntBox(this.get() + f.run(other));
        }
    }
}
