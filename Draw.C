void IdealWave()
{

	gStyle->SetPalette(1);
	gStyle->SetOptStat(0);
	gStyle->SetOptTitle(1);

    TCanvas *c1 = new TCanvas("c1","Wave Propagation",200,10,600,400);
 //    c1->Divide(1,9);
 //    c1->cd(1);
 //    TGraph *gr0 = new TGraph("Time0.dat");
 // 	gr0->GetYaxis()->SetRangeUser(-0.05,1.05);
	// gr0->SetLineColor(9);
 //    gr0->Draw("AC");

 //    c1->cd(2);
    TGraph *gr05 = new TGraph("FixedIdeal05.dat");
 	gr05->GetYaxis()->SetTitle("Power (arbitrary units)");
 	gr05->GetXaxis()->SetTitle("Frequency (Hz)");
 	gr05->SetTitle("Power Spectrum");
	gr05->SetLineColor(4);
	gr05->SetMarkerStyle(6);
    gr05->Draw("APC");

 //    c1->cd(3);
 //    TGraph *gr15 = new TGraph("Time15.dat");
 // 	gr15->GetYaxis()->SetRangeUser(-0.05,1.05);
	// gr15->SetLineColor(9);
 //    gr15->Draw("AC");

 //    c1->cd(4);
 //    TGraph *gr225 = new TGraph("Time225.dat");
 // 	gr225->GetYaxis()->SetRangeUser(-0.05,1.05);
	// gr225->SetLineColor(9);
 //    gr225->Draw("AC");

	// c1->cd(5);
 //    TGraph *gr5 = new TGraph("Time5.dat");
 // 	gr5->GetYaxis()->SetRangeUser(-0.05,1.05);
	// gr5->SetLineColor(9);
 //    gr5->Draw("AC");

	// c1->cd(6);
 //    TGraph *gr75 = new TGraph("Time75.dat");
 // 	gr75->GetYaxis()->SetRangeUser(-0.05,1.05);
	// gr75->SetLineColor(9);
 //    gr75->Draw("AC");

	// c1->cd(7);
 //    TGraph *gr90 = new TGraph("Time90.dat");
 // 	gr90->GetYaxis()->SetRangeUser(-0.05,1.05);
	// gr90->SetLineColor(9);
 //    gr90->Draw("AC");

	// c1->cd(8);
 //    TGraph *gr95 = new TGraph("Time95.dat");
 // 	gr95->GetYaxis()->SetRangeUser(-0.05,1.05);
	// gr95->SetLineColor(9);
 //    gr95->Draw("AC");

	// c1->cd(9);
 //    TGraph *gr100 = new TGraph("Time100.dat");
 // 	gr100->GetYaxis()->SetRangeUser(-0.05,1.05);
	// gr100->SetLineColor(9);
 //    gr100->Draw("AC");

}