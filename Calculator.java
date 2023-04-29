import java.awt.*;
import java.awt.event.*;

public class Calculator extends Frame implements ActionListener {
    private TextField displayField;
    private Button[] buttons;
    private String[] buttonLabels = { "7", "8", "9", "/", "4", "5", "6", "*", "1", "2", "3", "-", "0", ".", "=", "+" };
    private double result = 0;
    private String operator = "=";
    private boolean startOfNumber = true;

    public Calculator() {
        displayField = new TextField("", 20);
        buttons = new Button[buttonLabels.length];

        // Create buttons
        for (int i = 0; i < buttonLabels.length; i++) {
            buttons[i] = new Button(buttonLabels[i]);
            buttons[i].addActionListener(this);
        }

        // Set layout
        setLayout(new BorderLayout());
        add(displayField, BorderLayout.NORTH);

        // Add buttons to the frame
        Panel buttonPanel = new Panel();
        buttonPanel.setLayout(new GridLayout(4, 4));
        for (int i = 0; i < buttonLabels.length; i++) {
            buttonPanel.add(buttons[i]);
        }
        add(buttonPanel, BorderLayout.CENTER);

        // Add window listener
        addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent e) {
                dispose();
            }
        });

        // Set frame properties
        setTitle("Calculator");
        setSize(300, 300);
        setVisible(true);
    }

    public void actionPerformed(ActionEvent e) {
        String label = e.getActionCommand();
        if (label.equals("C")) {
            result = 0;
            operator = "=";
            displayField.setText("");
            startOfNumber = true;
        } else if ("0123456789.".indexOf(label) != -1) {
            if (startOfNumber) {
                displayField.setText(label);
            } else {
                displayField.setText(displayField.getText() + label);
            }
            startOfNumber = false;
        } else {
            if (startOfNumber) {
                if (label.equals("-")) {
                    displayField.setText(label);
                    startOfNumber = false;
                } else {
                    operator = label;
                }
            } else {
                double x = Double.parseDouble(displayField.getText());
                calculate(x);
                operator = label;
                startOfNumber = true;
            }
        }
    }

    private void calculate(double n) {
        if (operator.equals("+")) {
            result += n;
        } else if (operator.equals("-")) {
            result -= n;
        } else if (operator.equals("*")) {
            result *= n;
        } else if (operator.equals("/")) {
            result /= n;
        } else if (operator.equals("=")) {
            result = n;
        }
        displayField.setText("" + result);
    }

    public static void main(String[] args) {
        new Calculator();
    }
}
