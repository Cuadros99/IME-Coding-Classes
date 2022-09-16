package StringsExamples;

public class CifraDeCesar {

    int passo;

    public CifraDeCesar(int passo) {
        this.passo = passo;
    }

    public void criptografar(String msg) {
        char vectorMsg[] = msg.toCharArray();
        for(int i=0; i < msg.length(); i++) {
            if(vectorMsg[i] >= 'a' && vectorMsg[i] <= 'z' ) {
                vectorMsg[i] = (char)((vectorMsg[i] + passo - 'a')%26);
            }
            if(vectorMsg[i] >= 'A' && vectorMsg[i] <= 'Z' ) {
                vectorMsg[i] = (char)((vectorMsg[i] + passo - 'A')%26);
            }
        }
        String msgCripto = String.valueOf(vectorMsg);
        System.out.println(msgCripto);
    }

    public void descriptografar(String msgCripto) {
        char vectorMsg[] = msgCripto.toCharArray();
        for(int i=0; i < msgCripto.length(); i++) {
            if(vectorMsg[i] >= 'a' && vectorMsg[i] <= 'z' ) {
                vectorMsg[i] = (char)((vectorMsg[i] + passo - 'a')%26);
            }
            if(vectorMsg[i] >= 'A' && vectorMsg[i] <= 'Z' ) {
                vectorMsg[i] = (char)((vectorMsg[i] + passo - 'A')%26);
            }
            System.out.print(vectorMsg[i]);
        }
    }

}
