import quaternion.Quaternion;
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionListener;
import java.util.ArrayList;

public class QuaternionGUI {

    public static void main(String[] args) {
        JFrame frame = new JFrame("Quaternion Operations");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(1024, 768);
        frame.setLayout(new BorderLayout());
        frame.setResizable(false);

        ArrayList<Quaternion> quaternions = new ArrayList<>();

        JLabel newQuaternionLabel = new JLabel("Create Quaternion (Real, i, j, k):", SwingConstants.CENTER);
        JTextField realField = new JTextField(5);
        JTextField iField = new JTextField(5);
        JTextField jField = new JTextField(5);
        JTextField kField = new JTextField(5);
        JButton createButton = new JButton("Create Quaternion");

        JComboBox<String> quaternion1Selector = new JComboBox<>();
        JComboBox<String> quaternion2Selector = new JComboBox<>();

        JButton addButton = new JButton("Add");
        JButton subtractButton = new JButton("Subtract");
        JButton multiplyButton = new JButton("Multiply");
        JButton divideButton = new JButton("Divide");

        JLabel resultLabel = new JLabel("Result:");
        JTextArea resultArea = new JTextArea(5, 40);
        resultArea.setEditable(false);

        createButton.addActionListener(e -> {
            try {
                double real = Double.parseDouble(realField.getText());
                double i = Double.parseDouble(iField.getText());
                double j = Double.parseDouble(jField.getText());
                double k = Double.parseDouble(kField.getText());
                Quaternion newQuaternion = new Quaternion(real, i, j, k);
                quaternions.add(newQuaternion);
                quaternion1Selector.addItem("Q" + quaternions.size());
                quaternion2Selector.addItem("Q" + quaternions.size());
                resultArea.setText("Quaternion created: " + newQuaternion.toString());
            } catch (NumberFormatException ex) {
                JOptionPane.showMessageDialog(frame, "Please enter valid numbers.", "Error", JOptionPane.ERROR_MESSAGE);
            }
        });

        ActionListener operationListener = e -> {
            try {
                int index1 = quaternion1Selector.getSelectedIndex();
                int index2 = quaternion2Selector.getSelectedIndex();
                if (index1 < 0 || index2 < 0) {
                    throw new IllegalArgumentException("Please select valid quaternions.");
                }
                Quaternion q1 = quaternions.get(index1);
                Quaternion q2 = quaternions.get(index2);
                Quaternion result = null;

                if (e.getSource() == addButton) {
                    result = q1.add(q2.getReal(), q2.getI(), q2.getJ(), q2.getK());
                } else if (e.getSource() == subtractButton) {
                    result = q1.subtract(q2.getReal(), q2.getI(), q2.getJ(), q2.getK());
                } else if (e.getSource() == multiplyButton) {
                    result = q1.multiply(q2.getReal(), q2.getI(), q2.getJ(), q2.getK());
                } else if (e.getSource() == divideButton) {
                    result = q1.divide(q2.getReal(), q2.getI(), q2.getJ(), q2.getK());
                }

                assert result != null;
                resultArea.setText("Result: " + result);
            } catch (Exception ex) {
                JOptionPane.showMessageDialog(frame, ex.getMessage(), "Error", JOptionPane.ERROR_MESSAGE);
            }
        };

        addButton.addActionListener(operationListener);
        subtractButton.addActionListener(operationListener);
        multiplyButton.addActionListener(operationListener);
        divideButton.addActionListener(operationListener);

        JPanel panel = new JPanel();
        panel.setLayout(new GridBagLayout());
        GridBagConstraints gbc = new GridBagConstraints();
        gbc.insets = new Insets(5, 5, 5, 5);

        gbc.gridx = 0;
        gbc.gridy = 0;
        gbc.gridwidth = 4;
        gbc.anchor = GridBagConstraints.WEST;
        panel.add(newQuaternionLabel, gbc);

        gbc.gridy = 1;
        gbc.gridwidth = 1;
        gbc.fill = GridBagConstraints.HORIZONTAL;
        gbc.weightx = 0.25;
        panel.add(realField, gbc);
        gbc.gridx = 1;
        panel.add(iField, gbc);
        gbc.gridx = 2;
        panel.add(jField, gbc);
        gbc.gridx = 3;
        panel.add(kField, gbc);

        gbc.gridy = 2;
        gbc.gridx = 0;
        gbc.weightx = 0;
        panel.add(createButton, gbc);

        gbc.gridx = 0;
        gbc.gridy = 3;
        gbc.gridwidth = 1;
        panel.add(new JLabel("Select Q1:"), gbc);
        gbc.gridx = 1;
        panel.add(quaternion1Selector, gbc);
        gbc.gridx = 2;
        panel.add(new JLabel("Select Q2:"), gbc);
        gbc.gridx = 3;
        panel.add(quaternion2Selector, gbc);

        gbc.gridx = 0;
        gbc.gridy = 4;
        addButton.setPreferredSize(new Dimension(80, 30));
        panel.add(addButton, gbc);
        gbc.gridx = 1;
        subtractButton.setPreferredSize(new Dimension(80, 30));
        panel.add(subtractButton, gbc);
        gbc.gridx = 2;
        multiplyButton.setPreferredSize(new Dimension(80, 30));
        panel.add(multiplyButton, gbc);
        gbc.gridx = 3;
        divideButton.setPreferredSize(new Dimension(80, 30));
        panel.add(divideButton, gbc);

        gbc.gridx = 0;
        gbc.gridy = 5;
        gbc.gridwidth = 4;
        panel.add(resultLabel, gbc);

        gbc.gridy = 6;
        gbc.fill = GridBagConstraints.BOTH;
        gbc.weightx = 1;
        gbc.weighty = 1;
        panel.add(new JScrollPane(resultArea), gbc);

        frame.add(panel, BorderLayout.CENTER);
        frame.setVisible(true);
    }
}