// Vehicle - superclass
function Vehicle(name) {
    this.name = name;
}
// superclass method
Vehicle.prototype.start = function () {
    return "engine of " + this.name + " starting...";
};
// Car - subclass
function Car(name) {
    Vehicle.call(this, name); // call super constructor.
}
// subclass extends superclass
Car.prototype = Object.create(Vehicle.prototype);
// subclass method
Car.prototype.run = function () {
    console.log("Hello " + this.start());
};
// instances of subclass
var c1 = new Car("Fiesta");
var c2 = new Car("Baleno");

// accessing the subclass method which internally access superclass method
c1.run();   // "Hello engine of Fiesta starting..."
c2.run();   // "Hello engine of Baleno starting..."