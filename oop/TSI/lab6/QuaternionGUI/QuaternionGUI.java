import quaternion.Quaternion;
import java.awt.*;
import javax.swing.*;

public class QuaternionGUI {

    public static void main(String[] args) {
        // Create the main frame
        JFrame frame = new JFrame("Quaternion Operations");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(600, 400);

        // Create input fields for the first quaternion
        JLabel label1 = new JLabel("Quaternion 1 (Real, i, j, k):");
        JTextField real1Field = new JTextField(5);
        JTextField i1Field = new JTextField(5);
        JTextField j1Field = new JTextField(5);
        JTextField k1Field = new JTextField(5);

        // Create input fields for the second quaternion
        JLabel label2 = new JLabel("Quaternion 2 (Real, i, j, k):");
        JTextField real2Field = new JTextField(5);
        JTextField i2Field = new JTextField(5);
        JTextField j2Field = new JTextField(5);
        JTextField k2Field = new JTextField(5);

        // Create buttons for operations
        JButton addButton = new JButton("Add");
        JButton subtractButton = new JButton("Subtract");
        JButton multiplyButton = new JButton("Multiply");

        // Create an area to display the result
        JLabel resultLabel = new JLabel("Result:");
        JTextArea resultArea = new JTextArea(5, 40);
        resultArea.setEditable(false);

        // Add action listeners to buttons
        addButton.addActionListener(e -> {
            try {
                Quaternion q1 = readQuaternion(real1Field, i1Field, j1Field, k1Field);
                Quaternion q2 = readQuaternion(real2Field, i2Field, j2Field, k2Field);
                Quaternion result = q1.add(q2.getReal(), q2.getI(), q2.getJ(), q2.getK());
                resultArea.setText("Addition Result: " + result);
            } catch (NumberFormatException ex) {
                JOptionPane.showMessageDialog(frame, "Please enter valid numbers.", "Error", JOptionPane.ERROR_MESSAGE);
            }
        });

        subtractButton.addActionListener(e -> {
            try {
                Quaternion q1 = readQuaternion(real1Field, i1Field, j1Field, k1Field);
                Quaternion q2 = readQuaternion(real2Field, i2Field, j2Field, k2Field);
                Quaternion result = q1.subtract(q2.getReal(), q2.getI(), q2.getJ(), q2.getK());
                resultArea.setText("Subtraction Result: " + result);
            } catch (NumberFormatException ex) {
                JOptionPane.showMessageDialog(frame, "Please enter valid numbers.", "Error", JOptionPane.ERROR_MESSAGE);
            }
        });

        multiplyButton.addActionListener(e -> {
            try {
                Quaternion q1 = readQuaternion(real1Field, i1Field, j1Field, k1Field);
                Quaternion q2 = readQuaternion(real2Field, i2Field, j2Field, k2Field);
                Quaternion result = q1.multiply(q2.getReal(), q2.getI(), q2.getJ(), q2.getK());
                resultArea.setText("Multiplication Result: " + result);
            } catch (NumberFormatException ex) {
                JOptionPane.showMessageDialog(frame, "Please enter valid numbers.", "Error", JOptionPane.ERROR_MESSAGE);
            }
        });

        // Create a panel and add components to it
        JPanel panel = new JPanel();
        panel.setLayout(new GridLayout(7, 1));
        panel.add(label1);
        panel.add(createRow(real1Field, i1Field, j1Field, k1Field));
        panel.add(label2);
        panel.add(createRow(real2Field, i2Field, j2Field, k2Field));
        panel.add(createRow(addButton, subtractButton, multiplyButton));
        panel.add(resultLabel);
        panel.add(new JScrollPane(resultArea));

        // Add the panel to the frame
        frame.add(panel);
        frame.setVisible(true);
    }

    private static JPanel createRow(JComponent... components) {
        JPanel row = new JPanel();
        for (JComponent component : components) {
            row.add(component);
        }
        return row;
    }

    private static Quaternion readQuaternion(JTextField realField, JTextField iField, JTextField jField, JTextField kField) {
        double real = Double.parseDouble(realField.getText());
        double i = Double.parseDouble(iField.getText());
        double j = Double.parseDouble(jField.getText());
        double k = Double.parseDouble(kField.getText());
        return new Quaternion(real, i, j, k);
    }
}