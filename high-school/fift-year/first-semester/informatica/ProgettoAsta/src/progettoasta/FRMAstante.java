/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package progettoasta;

import java.awt.Color;
import java.util.Observable;
import java.util.Observer;

/**
 * Classe Frame Astante
 *
 * @author Farhan
 */
public class FRMAstante extends javax.swing.JFrame implements Observer {

    /*Attributi*/
    private MODAstante ma;
    private double bdg;
    private final String imgPth = "/Images/";

    /*Costruttore*/
    /**
     * Creates new frame Astante
     */
    public FRMAstante(MODAstante modello) {
        toDoFirst(modello);
        initComponents();
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        panNotifiche = new javax.swing.JPanel();
        lblTempo = new javax.swing.JLabel();
        lblNickName = new javax.swing.JLabel();
        lblSaldoDisponibile = new javax.swing.JLabel();
        panCentrale = new javax.swing.JPanel();
        panUtil = new javax.swing.JPanel();
        lblTitlePrezzo = new javax.swing.JLabel();
        lblPrezzo = new javax.swing.JLabel();
        lblTitleMgOff = new javax.swing.JLabel();
        lblMaggOff = new javax.swing.JLabel();
        lblTitlePrezzoAtt = new javax.swing.JLabel();
        lblPrezzoAtt = new javax.swing.JLabel();
        lblFoto = new javax.swing.JLabel();
        panTitle = new javax.swing.JPanel();
        lblNomeOggAsta = new javax.swing.JLabel();
        lblTitleProprietario = new javax.swing.JLabel();
        lblProprietario = new javax.swing.JLabel();
        panRilancio = new javax.swing.JPanel();
        lblTitleRilancio = new javax.swing.JLabel();
        txtRilancio = new javax.swing.JTextField();
        btnRilancio = new javax.swing.JButton();
        lblMessaggi = new javax.swing.JLabel();

        setDefaultCloseOperation(javax.swing.WindowConstants.DISPOSE_ON_CLOSE);
        setTitle("Astante");

        panNotifiche.setBackground(new java.awt.Color(204, 204, 204));

        lblTempo.setFont(new java.awt.Font("Tahoma", 0, 18)); // NOI18N
        lblTempo.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        lblTempo.setText("00:00");

        lblNickName.setFont(new java.awt.Font("Tahoma", 0, 18)); // NOI18N
        lblNickName.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        lblNickName.setText("Nome");

        lblSaldoDisponibile.setFont(new java.awt.Font("Tahoma", 0, 18)); // NOI18N
        lblSaldoDisponibile.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        lblSaldoDisponibile.setText("0 €");

        javax.swing.GroupLayout panNotificheLayout = new javax.swing.GroupLayout(panNotifiche);
        panNotifiche.setLayout(panNotificheLayout);
        panNotificheLayout.setHorizontalGroup(
            panNotificheLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(panNotificheLayout.createSequentialGroup()
                .addComponent(lblTempo, javax.swing.GroupLayout.PREFERRED_SIZE, 100, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(167, 167, 167)
                .addComponent(lblSaldoDisponibile, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addGap(163, 163, 163)
                .addComponent(lblNickName, javax.swing.GroupLayout.PREFERRED_SIZE, 100, javax.swing.GroupLayout.PREFERRED_SIZE))
        );
        panNotificheLayout.setVerticalGroup(
            panNotificheLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(panNotificheLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                .addComponent(lblTempo, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addComponent(lblNickName, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addComponent(lblSaldoDisponibile, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );

        panCentrale.setBackground(new java.awt.Color(255, 255, 255));

        lblTitlePrezzo.setFont(new java.awt.Font("Tahoma", 0, 18)); // NOI18N
        lblTitlePrezzo.setText("Prezzo di partenza: ");

        lblPrezzo.setBackground(new java.awt.Color(204, 255, 204));
        lblPrezzo.setFont(new java.awt.Font("Tahoma", 0, 24)); // NOI18N
        lblPrezzo.setText("0 €");

        lblTitleMgOff.setFont(new java.awt.Font("Tahoma", 0, 18)); // NOI18N
        lblTitleMgOff.setText("Maggior offerente: ");

        lblMaggOff.setBackground(new java.awt.Color(204, 255, 204));
        lblMaggOff.setFont(new java.awt.Font("Tahoma", 0, 24)); // NOI18N
        lblMaggOff.setText("Nessuno");

        lblTitlePrezzoAtt.setFont(new java.awt.Font("Tahoma", 0, 18)); // NOI18N
        lblTitlePrezzoAtt.setText("Prezzo attuale: ");

        lblPrezzoAtt.setBackground(new java.awt.Color(204, 255, 204));
        lblPrezzoAtt.setFont(new java.awt.Font("Tahoma", 0, 24)); // NOI18N
        lblPrezzoAtt.setText("0 €");

        javax.swing.GroupLayout panUtilLayout = new javax.swing.GroupLayout(panUtil);
        panUtil.setLayout(panUtilLayout);
        panUtilLayout.setHorizontalGroup(
            panUtilLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(panUtilLayout.createSequentialGroup()
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addGroup(panUtilLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING, false)
                    .addComponent(lblTitleMgOff, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(lblPrezzo, javax.swing.GroupLayout.Alignment.LEADING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(lblTitlePrezzo, javax.swing.GroupLayout.Alignment.LEADING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(lblMaggOff, javax.swing.GroupLayout.Alignment.LEADING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                .addGap(18, 18, 18)
                .addGroup(panUtilLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                    .addComponent(lblTitlePrezzoAtt, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(lblPrezzoAtt, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                .addGap(34, 34, 34))
        );
        panUtilLayout.setVerticalGroup(
            panUtilLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(panUtilLayout.createSequentialGroup()
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addGroup(panUtilLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(lblTitlePrezzo)
                    .addComponent(lblTitlePrezzoAtt))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(panUtilLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(lblPrezzo)
                    .addComponent(lblPrezzoAtt))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(lblTitleMgOff)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(lblMaggOff)
                .addGap(42, 42, 42))
        );

        lblFoto.setBackground(new java.awt.Color(204, 255, 204));
        lblFoto.setFont(new java.awt.Font("Tahoma", 0, 48)); // NOI18N
        lblFoto.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);

        lblNomeOggAsta.setFont(new java.awt.Font("Tahoma", 0, 48)); // NOI18N
        lblNomeOggAsta.setText("Titolo");

        lblTitleProprietario.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        lblTitleProprietario.setText("Proprietario: ");

        lblProprietario.setFont(new java.awt.Font("Tahoma", 0, 24)); // NOI18N
        lblProprietario.setText("Nome");
        lblProprietario.setVerticalAlignment(javax.swing.SwingConstants.BOTTOM);

        javax.swing.GroupLayout panTitleLayout = new javax.swing.GroupLayout(panTitle);
        panTitle.setLayout(panTitleLayout);
        panTitleLayout.setHorizontalGroup(
            panTitleLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(panTitleLayout.createSequentialGroup()
                .addContainerGap()
                .addGroup(panTitleLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(panTitleLayout.createSequentialGroup()
                        .addComponent(lblTitleProprietario)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(lblProprietario))
                    .addComponent(lblNomeOggAsta))
                .addGap(0, 0, Short.MAX_VALUE))
        );
        panTitleLayout.setVerticalGroup(
            panTitleLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(panTitleLayout.createSequentialGroup()
                .addComponent(lblNomeOggAsta)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(panTitleLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(panTitleLayout.createSequentialGroup()
                        .addGap(0, 0, Short.MAX_VALUE)
                        .addComponent(lblTitleProprietario))
                    .addComponent(lblProprietario, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                .addContainerGap())
        );

        lblTitleRilancio.setFont(new java.awt.Font("Tahoma", 0, 18)); // NOI18N
        lblTitleRilancio.setText("Rilancia: ");

        txtRilancio.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        txtRilancio.setHorizontalAlignment(javax.swing.JTextField.RIGHT);
        txtRilancio.setText("0");

        btnRilancio.setText("Rilancia");
        btnRilancio.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnRilancioActionPerformed(evt);
            }
        });

        lblMessaggi.setFont(new java.awt.Font("Tahoma", 0, 18)); // NOI18N
        lblMessaggi.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        lblMessaggi.setText("-");

        javax.swing.GroupLayout panRilancioLayout = new javax.swing.GroupLayout(panRilancio);
        panRilancio.setLayout(panRilancioLayout);
        panRilancioLayout.setHorizontalGroup(
            panRilancioLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(panRilancioLayout.createSequentialGroup()
                .addContainerGap()
                .addGroup(panRilancioLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING, false)
                    .addComponent(lblMessaggi, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(btnRilancio, javax.swing.GroupLayout.Alignment.LEADING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addGroup(panRilancioLayout.createSequentialGroup()
                        .addComponent(lblTitleRilancio)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(txtRilancio, javax.swing.GroupLayout.PREFERRED_SIZE, 555, javax.swing.GroupLayout.PREFERRED_SIZE)))
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );
        panRilancioLayout.setVerticalGroup(
            panRilancioLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(panRilancioLayout.createSequentialGroup()
                .addContainerGap()
                .addGroup(panRilancioLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(lblTitleRilancio)
                    .addComponent(txtRilancio, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(btnRilancio)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(lblMessaggi, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addContainerGap())
        );

        javax.swing.GroupLayout panCentraleLayout = new javax.swing.GroupLayout(panCentrale);
        panCentrale.setLayout(panCentraleLayout);
        panCentraleLayout.setHorizontalGroup(
            panCentraleLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(panCentraleLayout.createSequentialGroup()
                .addContainerGap()
                .addGroup(panCentraleLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(panRilancio, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addGroup(panCentraleLayout.createSequentialGroup()
                        .addComponent(lblFoto, javax.swing.GroupLayout.PREFERRED_SIZE, 325, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                        .addGroup(panCentraleLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(panUtil, javax.swing.GroupLayout.PREFERRED_SIZE, 0, Short.MAX_VALUE)
                            .addComponent(panTitle, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))))
                .addContainerGap())
        );
        panCentraleLayout.setVerticalGroup(
            panCentraleLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(panCentraleLayout.createSequentialGroup()
                .addGroup(panCentraleLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                    .addGroup(panCentraleLayout.createSequentialGroup()
                        .addComponent(panTitle, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                        .addComponent(panUtil, javax.swing.GroupLayout.PREFERRED_SIZE, 141, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addComponent(lblFoto, javax.swing.GroupLayout.PREFERRED_SIZE, 261, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(panRilancio, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(panNotifiche, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
            .addComponent(panCentrale, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addComponent(panNotifiche, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(panCentrale, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents
    /**
     * Metodo che cattura l' evento del button "Rilancia"
     *
     * @param evt (ActionEvent)
     */
    private void btnRilancioActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnRilancioActionPerformed
        try {
            double offRilancio = Double.parseDouble(txtRilancio.getText());
            if (offRilancio > bdg) {
                lblMessaggi.setText("Questa offerta supera il badget!");
            } else {
                if (!ma.isCntDwnFinished()) {
                    ma.setOfferta(offRilancio);
                    lblMessaggi.setText("Hai rilanciato con sucesso!");
                } else {
                    lblMessaggi.setText("Tempo Scaduto!");
                }
            }
        } catch (Exception e) {
            lblMessaggi.setText("Offerta non valido!");
        }
    }//GEN-LAST:event_btnRilancioActionPerformed

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton btnRilancio;
    private javax.swing.JLabel lblFoto;
    private javax.swing.JLabel lblMaggOff;
    private javax.swing.JLabel lblMessaggi;
    private javax.swing.JLabel lblNickName;
    private javax.swing.JLabel lblNomeOggAsta;
    private javax.swing.JLabel lblPrezzo;
    private javax.swing.JLabel lblPrezzoAtt;
    private javax.swing.JLabel lblProprietario;
    private javax.swing.JLabel lblSaldoDisponibile;
    private javax.swing.JLabel lblTempo;
    private javax.swing.JLabel lblTitleMgOff;
    private javax.swing.JLabel lblTitlePrezzo;
    private javax.swing.JLabel lblTitlePrezzoAtt;
    private javax.swing.JLabel lblTitleProprietario;
    private javax.swing.JLabel lblTitleRilancio;
    private javax.swing.JPanel panCentrale;
    private javax.swing.JPanel panNotifiche;
    private javax.swing.JPanel panRilancio;
    private javax.swing.JPanel panTitle;
    private javax.swing.JPanel panUtil;
    private javax.swing.JTextField txtRilancio;
    // End of variables declaration//GEN-END:variables
    /**
     * Metodo utilizzato nel costruttore per inizializzare gli attributi
     *
     * @param modello (MODAstante)
     */
    private void toDoFirst(MODAstante modello) {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(FRMBanditore.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(FRMBanditore.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(FRMBanditore.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(FRMBanditore.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            @Override
            public void run() {
                setVisible(true);
            }
        });
        this.ma = modello;
        this.bdg = 0;
    }

    /**
     * Metodo update del Observer
     *
     * @param o (Observable): MODAstante,CntCwnTimer,ArticoloAsta
     * @param arg (Object)
     */
    @Override
    public void update(Observable o, Object arg) {
        if (o instanceof MODAstante && arg != null) {
            if (arg instanceof String) {
                lblNickName.setText("" + arg);
            } else if (arg instanceof Double) {
                bdg = (double) arg;
                lblSaldoDisponibile.setText(bdg + " €");
            } else if (arg instanceof MODAstante) {
                setFirstAstante((MODAstante) arg);
            } else if (arg instanceof ArticoloAsta) {
                setArticolo((ArticoloAsta) arg);
            }
        } else if (o instanceof CntDwnTimer) {
            setTimer(arg);
        }
    }

    /**
     * Metodo che definisce il layout della schermata quando sa il primo astante
     *
     * @param modello (MODAstante)
     */
    private void setFirstAstante(MODAstante modello) {
        lblMaggOff.setText(modello.getNome());
        lblPrezzoAtt.setText("" + modello.getOfferta());
    }

    /**
     * Metodo che definisce il layout della schermata quando sa l'articolo
     * all'asta
     *
     * @param art (ArticoloAsta)
     */
    private void setArticolo(ArticoloAsta art) {
        lblNomeOggAsta.setText(art.getName());
        lblProprietario.setText(art.getOwner());
        lblPrezzo.setText(art.getPrezzo() + " €");
        lblPrezzoAtt.setText("0 €");
        lblFoto.setIcon(new javax.swing.ImageIcon(getClass().getResource(imgPth + art.getFotoName())));
    }

    /**
     * Metodo che definisce il layout della schermata quando sa il tempo
     *
     * @param timer (Object)
     */
    private void setTimer(Object timer) {
        lblTitleMgOff.setText(ma.isCntDwnFinished() ? "Ha Vinto: " : "Maggior offerente: ");
        int[] temp = (int[]) timer;
        String MIN = (temp[0] < 10 ? "0" + temp[0] : "" + temp[0]);
        String SEC = (temp[1] < 10 ? "0" + temp[1] : "" + temp[1]);
        lblTempo.setForeground(temp[0] < 1 ? Color.RED : Color.BLACK);
        lblTempo.setText(MIN + ":" + SEC);
    }

}