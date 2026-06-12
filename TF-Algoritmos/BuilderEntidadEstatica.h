#pragma once
#include "EntidadEstatica.h"

EntidadEstatica^ setupNINivel1Mapa1Lenador1() {
    // Lista de opciones 0
    List<Opcion^>^ opciones0 = gcnew List<Opcion^>();
    opciones0->Add(gcnew Opcion(
        L"Increparlo",
        gcnew List<int>(gcnew array<int>{0, 0, 1}),
        1
    ));
    opciones0->Add(gcnew Opcion(
        L"Preguntar acerca de los anteriores periodistas",
        gcnew List<int>(gcnew array<int>{0, 0, 1}),
        3, 0
    ));
    opciones0->Add(gcnew Opcion(
        L"Preguntar de Kametsa Pampa",
        gcnew List<int>(gcnew array<int>{0, 0, 1}),
        4, 0
    ));
    opciones0->Add(gcnew Opcion(
        L"Preguntar acerca de él",
        gcnew List<int>(gcnew array<int>{0, 0, 1}),
        5, 0
    ));

    // Ejemplo de opción individual
    Opcion^ pp = gcnew Opcion(
        L"Increparlo",
        gcnew List<int>(gcnew array<int>{0, 0, 1}),
        1
    );

    // Lista de opciones 1
    List<Opcion^>^ opciones1 = gcnew List<Opcion^>();
    opciones1->Add(gcnew Opcion(
        L"Quería decir algo más...",
        gcnew List<int>(gcnew array<int>{0, 0, 0}),
        0
    ));

    Dialogo^ d0 = gcnew Dialogo(
        gcnew List<String^>(gcnew array<String^>{
        L"LEÑADOR 1: ¿Te quedó  alguna  duda,  periodista? He sido bastante claro contigo,",
        L"¿o quieres que te lo explique con manzanitas? Creo que eres alguien inteligente,",
        L"así que hazme caso, y todos salimos ganando."
    }),
        opciones0
    );

    Dialogo^ d1 = gcnew Dialogo(
        gcnew List<String^>(gcnew array<String^>{
        L"MATEO: Te estás confundiendo. Yo no soy como los anteriores periodistas.  Yo sí",
        L"tengo escrúpulos, y una patológica obsesión por la  verdad.  He lidiado  con la",
        L"gente, con la clase luchadora y con charlatanes. Aunque no lo parezca, yo tengo",
        L"experiencia lidiando con indeseables.  Y no soy estúpido. Sé como funciona este",
        L"juego, y tomé las  precauciones  necesarias  antes de partir. Aunque debo agra-",
        L"decerte por la cordial bienvenida. Me aseguraré de incluirlo en la nota.",
        L"                          [Presiona E para continuar]"
    }),
        2,
        true
    );

    Dialogo^ d2 = gcnew Dialogo(
        gcnew List<String^>(gcnew array<String^>{
        L"LEÑADOR 1: Oh, no te molestes. Yo solo intentaba ser amable. Viendo que eres un",
        L"malcriado, actuaré como  tal.  Te  recomiendo vigilar tus espaldas, periodista.",
        L"Aquí el conocimiento tiene precio, y tú no tienes como pagarlo.",
        L"Lamentaría que tu balsa  se  hunda,  que  tu  comida  sorpresivamente  te  haga",
        L"mal, o que se oigan rumores  que pongan al pueblo contra ti.  Imagínate... 'Pe-",
        L"riodista limeño desaparece tras un viaje a la selva'... Ahora, lárgate."
    }),
        opciones1
    );

    Dialogo^ d3 = gcnew Dialogo(
        gcnew List<String^>(gcnew array<String^>{
        L"LEÑADOR 1: ¿Oh, los otros periodistas? No lidiamos con ellos desde hace dos largos",
        L"años. Los que se aventuraron cambiaban su rumbo tras peculiares emergencias, o de-",
        L"sertaban antes de sarpar. Claro, algunos llegaron  aquí... pero  tras  una  amical",
        L"charla los convencimos a no hurgar donde  no tenían negocio  alguno.  Ellos fueron",
        L"muy cooperativos.  Espero que tú también lo seas."
    }),
        opciones1
    );

    Dialogo^ d4 = gcnew Dialogo(
        gcnew List<String^>(gcnew array<String^>{
        L"LEÑADOR 1: Un pueblecillo  infame  por  su  pasión  por la  agresión  gratuita.",
        L"¿Sabías que el susodicho líder del pueblo, Evaristo, fue denunciado penalmente,",
        L"por usurpación de terrenos? Este hombre y su  gente  fue  tan  fresca  de inva-",
        L"invadir tierra que pertenence legalmente a la maderera.  ¿Qué  se  puede  espe-",
        L"rar de esa calaña? Odian a los forasteros.  Odian a los trabajadores como yo, y",
        L"ciertamente, no se molestarán en decirte ni una sola palabra."
    }),
        opciones1
    );

    Dialogo^ d5 = gcnew Dialogo(
        gcnew List<String^>(gcnew array<String^>{
        L"LEÑADOR 1: ¿Yo?  Solo soy un  trabajador  encargado a vigilar esta zona, que le-",
        L"galmente le pertenece a la empresa  en la que trabajo y  la cuál ha sido triste-",
        L"mente agregida por la comunidad.  ¿Te imaginas?  Nos han atacado constantemente,",
        L"y quién sabe que hubiese  pasado  si  no  hubiese sido por la intervención de la",
        L"justicia. Desde ese momento, están calmados.  Sería muy lamentable si algún agi-",
        L"tador viniese a quebrar la paz..."
    }),
        opciones1
    );

    ArbolDialogo^ arbl1 = gcnew ArbolDialogo();
    arbl1->agregarDialogo(d0);
    arbl1->agregarDialogo(d1);
    arbl1->agregarDialogo(d2);
    arbl1->agregarDialogo(d3);
    arbl1->agregarDialogo(d4);
    arbl1->agregarDialogo(d5);

    EntidadEstatica^ lenador1 = gcnew EntidadEstatica(450, 250, gcnew Bitmap("sprites\\entidades\\talador_idle.png"), arbl1);

    return lenador1;
}