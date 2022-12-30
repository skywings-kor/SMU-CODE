
public class MyCar {
	//대상을 정의하는 특성값: 필드
	String model;
	String vender;
	String carNumber;
	String owner;
	
	//생성자의 이름은 반드시 class와 동일해야한다
	
	public MyCar(String m,String v,String cn,String o)
	{
		//객체가 생성될 때의 초기화 구문 또는 초기값 설정
		this.model=m;
		this.vender=v;
		this.carNumber=cn;
		this.owner=o;
	}
	
	
	//대상의 기능을 정의하는 코드: 메소드
	public String getModel()		//읽기
	{
		return this.model;
	}
	
	public void setModel(String model)	//쓰기
	{
		this.model=model;		//this는 String model 위에 선언한 것에 값 넣는 것
	}
	
	public void printCarInfo()
	{
		System.out.printf("모델-> %s , 생산자->%s, 등록번호->%s, 소유자:%s \n",this.model,this.vender,this.carNumber,this.owner);
		
	}
	
	
	
	
}
