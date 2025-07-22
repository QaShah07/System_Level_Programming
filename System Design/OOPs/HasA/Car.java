public class Car {
    private Engine engine;  // Composition: Car HAS AN Engine

    public Car() {
        this.engine = new Engine();
    }

    public void start() {
        engine.ignite();
    }
}
