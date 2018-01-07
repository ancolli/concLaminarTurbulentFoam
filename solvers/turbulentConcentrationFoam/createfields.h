    Info<< "Reading field C\n" << endl;

    volScalarField C
    (
        IOobject
        (
            "C",
            runTime.timeName(),
            mesh,
            IOobject::MUST_READ,
            IOobject::AUTO_WRITE
        ),
        mesh
    );

    Info<< "Reading field nut\n" << endl;

    volScalarField nut
    (
        IOobject
        (
            "nut",
            runTime.timeName(),
            mesh,
            IOobject::MUST_READ,
            IOobject::AUTO_WRITE
        ),
        mesh
    );

    Info<< "Reading field U\n" << endl;

    volVectorField U
    (
        IOobject
        (
            "U",
            runTime.timeName(),
            mesh,
            IOobject::MUST_READ,
            IOobject::AUTO_WRITE
        ),
        mesh
    );


    Info<< "Reading transportProperties\n" << endl;

    IOdictionary transportProperties
    (
        IOobject
        (
            "transportProperties",
            runTime.constant(),
            mesh,
            IOobject::MUST_READ_IF_MODIFIED,
            IOobject::NO_WRITE
        )
    );


    Info<< "Reading diffusivity D\n" << endl;

    dimensionedScalar Dmol
    (
        transportProperties.lookup("Dmol")
    );

    Info<< "Reading turbulent Schmidt number\n" << endl;

    dimensionedScalar Sct
    (
        transportProperties.lookup("Sct")
    );

    volScalarField Deff
    (
        IOobject
        (
            "Deff",
            runTime.timeName(),
            mesh,
            IOobject::MUST_READ,//NO_READ,
            IOobject::AUTO_WRITE//NO_WRITE
        ),
        nut/Sct + Dmol,
        nut.boundaryField().types()
    );

#   include "createPhi.H"
