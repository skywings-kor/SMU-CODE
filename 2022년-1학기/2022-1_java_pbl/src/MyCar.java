
public class MyCar {
	//����� �����ϴ� Ư����: �ʵ�
	String model;
	String vender;
	String carNumber;
	String owner;
	
	//�������� �̸��� �ݵ�� class�� �����ؾ��Ѵ�
	
	public MyCar(String m,String v,String cn,String o)
	{
		//��ü�� ������ ���� �ʱ�ȭ ���� �Ǵ� �ʱⰪ ����
		this.model=m;
		this.vender=v;
		this.carNumber=cn;
		this.owner=o;
	}
	
	
	//����� ����� �����ϴ� �ڵ�: �޼ҵ�
	public String getModel()		//�б�
	{
		return this.model;
	}
	
	public void setModel(String model)	//����
	{
		this.model=model;		//this�� String model ���� ������ �Ϳ� �� �ִ� ��
	}
	
	public void printCarInfo()
	{
		System.out.printf("��-> %s , ������->%s, ��Ϲ�ȣ->%s, ������:%s \n",this.model,this.vender,this.carNumber,this.owner);
		
	}
	
	
	
	
}
