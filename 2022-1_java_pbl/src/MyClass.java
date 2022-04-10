
public class MyClass {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		//인스턴스 객체를 생성
		MyCar car1=new MyCar("티코","대우","21-6969","이해준");		//MyCar라는것이 데이터 타입이 된것이다 결국 public로 해서
		MyCar car2=new MyCar("제네시스","현대","28-2323","박규민");		//MyCar라는것이 데이터 타입이 된것이다 결국 public로 해서
		
		
		//메소드 호출
		car1.printCarInfo();
		
		car2.printCarInfo();
	
	}

}
