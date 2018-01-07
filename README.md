# v1.0.0
# concLaminarTurbulentFoam
Script based on scalarTransportFoam in order to predict, with the help of Navier-Stokes, laminar and turbulent mass-transfer behaviour in electrochemical reactors.

# Disclaimer
This offering is not approved or endorsed by OpeFOAM Foundation, producer and distributor of the OpenFOAM software via www.openfoam.org.

# Usage
In solvers (A) you will find the scripts to compile the solvers in order to solve the concentration field either in laminar or turbulent conditions knowing the velocity profile.  
In tutorial (B) you will find an example for a parallel plates reactor with high aspect ratio (elecrode width/interelectrode gap).

# #  A) Compile Solvers
1- Paste concentrationFoam and/or turbulentConcentrationFoam inside OpenFOAM user directory (Applications/Utilities/Solvers).  
2- Enter to concentrationFoam and/or turbulentConcentrationFoam and open a terminal.  
3- Run wmake.

# #  B) Run tutorial
1- Paste Navier-Stokes and concentration inside OpenFOAM user directory (Run/Tutorials).  
2- Enter to Navier-Stokes and open a Terminal.
3- Modify properties inside constant folder for laminar or turbulent flow.    
4- Run blockMesh and then Run simpleFoam.  
5- Paste U (laminar and turbulent ) and nut (turbulent) obtained as solution inside the 0 folder of concentration.  
6- Open a terminal inside concentration and Run blockMesh, then Run concentrationFoam (laminar) or turbulentConcentrationFoam (turbulent).
