import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.Statement;

public class DatabaseConnection {
	public static void main(String[] args) {
		String url = "jdbc:mysql://localhost:3306/yourDatabaseName";
		String user = "yourUsername";
		String password = "yourPassword";

		try {
			// Load the JDBC driver
			Class.forName("com.mysql.cj.jdbc.Driver");

			// Establish the connection
			Connection connection = DriverManager.getConnection(url, user, password);

			// Create a statement
			Statement statement = connection.createStatement();

			// Execute a query
			ResultSet resultSet = statement.executeQuery("SELECT * FROM yourTableName");

			// Process the result set
			while (resultSet.next()) {
				System.out.println("Column1: " + resultSet.getString("column1"));
				System.out.println("Column2: " + resultSet.getString("column2"));
			}

			// Close the connections
			resultSet.close();
			statement.close();
			connection.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}