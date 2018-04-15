package factory;

public class FigureFactory {
	public Figure create(FigureType figuretype){
		switch (figuretype){
		case SQUARE:
			return new Square();
		case TRIANGLE:
			return new Triangel();
		default:
			throw new IllegalArgumentException();
		}
	}
}
