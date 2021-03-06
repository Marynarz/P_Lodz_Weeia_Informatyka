package invoice;

public class Invoice {
	private String productId;
	private String productDesc;
	private int productQuantity;
	private double pricePerOne;
	
	public Invoice(String id, String desc, int quant, double price){
		this.setId(id);
		this.setDesc(desc);
		this.setQuant(quant);
		this.setPrice(price);
	}
	private void setId(String id)
	{
		this.productId = id;
	}
	private void setDesc(String desc)
	{
		this.productDesc = desc;
	}
	private void setQuant(int quant)
	{
		this.productQuantity = quant;
	}
	private void setPrice(double price)
	{
		this.pricePerOne = price;
	}
	public String getId()
	{
		return this.productId;
	}
	public String getDesc()
	{
		return this.productDesc;
	}
	public int getQuantity()
	{
		return this.productQuantity;
	}
	public double getPrice()
	{
		return this.pricePerOne;
	}
	public double getInvoiceAmount()
	{
		return this.pricePerOne * this.productQuantity;
	}
	public void showInvoice()
	{
		System.out.println("Id produktu: "+this.getId());
		System.out.println("Opis: "+this.getDesc());
		System.out.println("Ilosc: "+this.getQuantity());
		System.out.println("Cena jednostkowa: "+this.getPrice());
		System.out.println("Wartosc zamowienia: "+this.getInvoiceAmount());
	}
}
