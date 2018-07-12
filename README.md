# BACCARAT_1ExtractedElectron

I display the code for simulating 1 electron randomly within a circle at the liquid surface of the LZ detector.

Begin with the macro. This uses BACCARAT to run ~10000 simulations.
I convert the bin file that is generated to a rootfile. Rootfile is included.
I convert the root file to a csv file using the "Analyzing a File" code. "Analyzing A File" code is included. Csv file is included.
This csvfile contains the number of photons that hit each PMT photocathode. Each newline is a new event.
I have three python programs included that take this csvfile and extract visual displays of information from it. 
1)EfficiencyTables_WilsonScoreInterval
  This applies various trigger configurations and creates a table of trigger efficiencies for each trigger configuration.
2)TriggerPlots_Simplified__WilsonScoreInterval
  This applies various trigger configurations and creates a plot of trigger efficiencies for each trigger configuration.
3)PrintArrays_binom
  This shows the a visual of the top array light distribution.
