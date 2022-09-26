package g55047.humbug;

import com.fasterxml.jackson.databind.ObjectMapper;
import g55047.humbug.model.Position;
import java.io.IOException;

/**
 *
 * @author mar-w
 */
public class Test {

    public static void main(String[] args) throws IOException {
        var objectMapper = new ObjectMapper();
        var in = Test.class.getResourceAsStream("/data/position.json");
        Position position = objectMapper.readValue(in, Position.class);
        System.out.println("Position read: " + position);
    }
}
