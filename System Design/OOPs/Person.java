public class Person {
	private String name;
	private int age;
	// constructor
	public Person(String name ,int age)
	{
		this.name = name;
		this.age = age;
	}
	// Method
	public void introduce()
	{
		System.out.println("Hi, I am " + name + " and I am " + age + " years old.");
	}
}