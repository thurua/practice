package buoi1;
class tongdayso {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		float f=0.0f,tong=0.0f;
		for (String c: args){
			try{
				f= Float.parseFloat (c);
			}
				catch (Exception e){
					f=0.0f;
				}
				tong=tong+f;
			}
			System.out.print  ("tong day so doi so="+tong);}}	