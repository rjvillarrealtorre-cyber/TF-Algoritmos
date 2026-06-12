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

EntidadEstatica^ setupNINivel1Mapa2Wilmer() {
    List<Opcion^>^ opciones0 = gcnew List<Opcion^>();
    opciones0->Add(gcnew Opcion(L"Así que me estaban esperando...", gcnew List<int>(gcnew array<int>{0,0,1}), 1));
    opciones0->Add(gcnew Opcion(L"¿Los Mudo?", gcnew List<int>(gcnew array<int>{0,0,1}), 2));
    opciones0->Add(gcnew Opcion(L"¿Solo una molestia menor? ¿Te estás refiriendo a los anteriores periodistas, no?", gcnew List<int>(gcnew array<int>{0,0,1}), 3));
    opciones0->Add(gcnew Opcion(L"[Asentir con la cabeza y no decir nada]", gcnew List<int>(gcnew array<int>{0,0,1}), 4));

    List<Opcion^>^ opciones1 = gcnew List<Opcion^>();
    opciones1->Add(gcnew Opcion(L"[Asentir con la cabeza]", gcnew List<int>(gcnew array<int>{0,0,0}), 4));
    opciones1->Add(gcnew Opcion(L"Quisiera preguntarte algo más... [Volver]", gcnew List<int>(gcnew array<int>{0,0,0}), 0));

    Dialogo^ d0 = gcnew Dialogo(
        gcnew List<String^>(gcnew array<String^>{
            L"WILMER: Ah... es el periodista. No creas que has pasado desapercibido. Supimos que al-",
            L"guien iba a llegar cuando Los Mudo empezaron a actuar diferente. No estaban nerviosos,",
            L"solo irritados. Otra molestia más, aunque menor, que tenían que lidiar."
        }), opciones0);

    Dialogo^ d1 = gcnew Dialogo(
        gcnew List<String^>(gcnew array<String^>{
            L"WILMER: Sí, y no te debería sorprender.   ¿Escuchaste de los otros periodistas, no? Se",
            L"desanimaban en  medio del camino.   Así pasó durante los dos últimos años.  Recibíamos",
            L"rumores de sus inminentes llegadas... y nadie pisó ni la orilla. Ciertamente, has sido",
            L"la excepción a la regla."
        }), opciones1);

    Dialogo^ d2 = gcnew Dialogo(
        gcnew List<String^>(gcnew array<String^>{
            L"WILMER: Bueno, es un mal ejemplo para tu caso, ¡siendo que has tenido larga charla con",
            L"ellos! Nunca lo había visto tan de cerca, ¡Parece que tienen muy buena labia! Pero va-",
            L"yamos al grano.  Los llamamos así por que nunca hablan con nadie, ni siquiera entre e-",
            L"llos mismos... salvo que quieran convencer a alguien, como lo hicieron contigo..."
        }), opciones1);

    Dialogo^ d3 = gcnew Dialogo(
        gcnew List<String^>(gcnew array<String^>{
            L"WILMER: Sí, y quizás estoy siendo muy generoso con su impacto.  Nuestros amigos perio-",
            L"distas se desviaban del camino, y los pocos que llegaron, dieron mala fama a su profe-",
            L"sión.  ¿Luchar por la verdad?  Ellos solamente tomaban fotos a la aldea y al sol mien-",
            L"tras evitaban los tocones o el río. Luego se largaban, y la aldea quedó igual, o peor."
        }), opciones1);

    Dialogo^ d4 = gcnew Dialogo(
        gcnew List<String^>(gcnew array<String^>{
            L"WILMER:  Periodista, entenderás mi inquietud al verte.  Eres el primero en pisar estas",
            L"tierras en dos años, pero  no  creas que no hemos lidiado con tus compañeros de oficio",
            L"tiempo atrás. ¿Los Mudo lograron convencerte, eh? ¿O de verdad quieres venderte  como",
            L"la excepción a la regla?",
            L"",
            L"                             [Presiona E para continuar]"
        }));

    List<Opcion^>^ opciones2 = gcnew List<Opcion^>();
    opciones2->Add(gcnew Opcion(L"No me dejé convencer. Por eso no me marché. Quiero ser la excepción a la regla.", gcnew List<int>(gcnew array<int>{5,0,0}), 6));
    opciones2->Add(gcnew Opcion(L"Ya lo dijiste. Soy periodista. Vine a hacer mi trabajo, nada más.", gcnew List<int>(gcnew array<int>{0,0,0}), 7));
    opciones2->Add(gcnew Opcion(L"No tengo por qué contarle mis intenciones a nadie.", gcnew List<int>(gcnew array<int>{-5,0,0}), 7));

    List<Opcion^>^ opciones3 = gcnew List<Opcion^>();
    opciones3->Add(gcnew Opcion(L"Vengo de estar con los pobladores. He aprendido mucho. [MIN. CONF: 30] [ACABAR NIVEL]", gcnew List<int>(gcnew array<int>{0,0,0}), 7, 30, 0, true));

    Dialogo^ d5 = gcnew Dialogo(
        gcnew List<String^>(gcnew array<String^>{
            L"WILMER: Así que, ¿Qué quieres aquí?  ¿Vas a tomar sus recomendaciones, y venderle men-",
            L"tiras al mundo, o marcharte misteriosamente esta misma tarde?"
        }), opciones2);

    Dialogo^ d6 = gcnew Dialogo(
        gcnew List<String^>(gcnew array<String^>{
            L"WILMER: Ah... te crees diferente. Y en parte, lo eres. No te has marchado aún.  Ese es",
            L"un  logro.  Hablas  con  coraje,  y  no  con  las  excusas  pusilánimes  de los que te",
            L"precedieron. Pero te digo desde ya: la confianza no se regala, se gana.  Si eres dife-",
            L"rente, demuéstralo. Hay muchos de nosotros que necesitan un par de brazos más.  Quizás",
            L"así puedas mostrarnos, a todos, que tus palabras concuerdan con tus actos."
        }), opciones3);

    Dialogo^ d7 = gcnew Dialogo(
        gcnew List<String^>(gcnew array<String^>{
            L"WILMER: ¿Así que todo el espectáculo fue para nada? Vamos, en realidad no me sorprende",
            L"en lo absoluto. Pero, en caso quieras cambiar de opinión, y demostrar que de verdad e-",
            L"res alguien que vale la pena, actúa. No con palabras bonitas, sino con actos valiosos.",
            L"El pueblo necesita ayuda. Y tú puedes ofrecérsela."
        }), opciones3);

    ArbolDialogo^ arbl0 = gcnew ArbolDialogo();
    arbl0->agregarDialogo(d0);
    arbl0->agregarDialogo(d1);
    arbl0->agregarDialogo(d2);
    arbl0->agregarDialogo(d3);
    arbl0->agregarDialogo(d4);
    arbl0->agregarDialogo(d5);
    arbl0->agregarDialogo(d6);
    arbl0->agregarDialogo(d7);

    EntidadEstatica^ wilmer = gcnew EntidadEstatica(220, 220, gcnew Bitmap("sprites\\entidades\\wilmer_idle.png"), arbl0);

    return wilmer;
}

EntidadEstatica^ setupNINivel1Mapa2Kevin() {
    List<Opcion^>^ opciones0 = gcnew List<Opcion^>();
    opciones0->Add(gcnew Opcion(L"Se llaman trenes eléctricos. Y quizás se puede decir que vuelan...", gcnew List<int>(gcnew array<int>{0,0,0}), 1));
    opciones0->Add(gcnew Opcion(L"No, es una exageración. Son trenes peculiares, nada más.", gcnew List<int>(gcnew array<int>{0,0,0}), 2));

    Dialogo^ d0 = gcnew Dialogo(gcnew List<String^>(gcnew array<String^>{
        L"[Kevin está sentado, jugando con un palito en la chacra. Es pequeño, quizás de 10 a 12",
        L"años. Al verte, te mira extrañado. Su expresión es curiosa, y no agresiva]",
        L"KEVIN: ¡Ey! ¿Eres tú el periodista, ese que Wilmer mencionó?  ¡Wow! ¡Pensé  que nunca",
        L"más volvería a ver uno! ¿Vienes de Lima, no? ¿Es verdad que ahí hay trenes que vuelan?"
    }), opciones0);

    List<Opcion^>^ opciones1 = gcnew List<Opcion^>();
    opciones1->Add(gcnew Opcion(L"Está bien, pero por un momento. Y la cuidas, por favor.", gcnew List<int>(gcnew array<int>{1,0,0}), 3));
    opciones1->Add(gcnew Opcion(L"Lo siento, es mi herramienta de trabajo. No puedo.", gcnew List<int>(gcnew array<int>{0,0,0}), 4));

    Dialogo^ d1 = gcnew Dialogo(gcnew List<String^>(gcnew array<String^>{
        L"KEVIN:  ¿Trenes eléctricos?  ¿Vuelan gracias a la electricidad?  ¡Espero algún día ver",
        L"uno!  Pero, ey, ¡aún hay mucho tiempo por delante!  ¿Y sí eres periodista?  ¿Qué es lo",
        L"que haces? ¿Entrevistas gente? ¿Investigas casos peligrosos?  ¿Siempre llevando tu cá-",
        L"mara? ¿Me la puedes dar, por un ratito? Quisiera grabar a mi abuela cantar. Ella canta",
        L"bonito en asháninka."
    }), opciones1);

    Dialogo^ d2 = gcnew Dialogo(gcnew List<String^>(gcnew array<String^>{
        L"KEVIN:  Oh... Wilmer siempre exagera las cosas.  Pero eso no quita que son trenes.  ¡Y",
        L"trenes peculiares! Yo nunca vi un tren.  Ni carros.  Solo las motos que algunos de los",
        L"cinos tienen. Pero tú eres de Lima... ¿Periodista, sí?  ¿Qué es lo que haces?  ¿Grabas",
        L"gente? ¿Me puedes dar tu grabadora, un ratito?  Quisiera grabar a mi abuela cantar. E-",
        L"lla canta bonito en asháninka."
    }), opciones1);

    List<Opcion^>^ opciones3 = gcnew List<Opcion^>();
    opciones3->Add(gcnew Opcion(L"¿Algo más? ¿Qué es lo que pasa?", gcnew List<int>(gcnew array<int>{5,5,5}), 5));

    Dialogo^ d3 = gcnew Dialogo(gcnew List<String^>(gcnew array<String^>{
        L"KEVIN: ¡Gracias, gracias! ¡Ahora vuelvo! [Kevin toma la cámara y entre tropezones, de-",
        L"saparece  entre las cabañas.  Pasan algunos minutos, y se le puede observar en la dis-",
        L"tancia. Tiene una sonrisa nerviosa en el rostro]",
        L"¡Lo hice! ¡Grabé a mi abuelita! Pero... también grabé algo más."
    }), opciones3);

    List<Opcion^>^ opciones4 = gcnew List<Opcion^>();
    opciones4->Add(gcnew Opcion(L"Cambié de opinión. Ten, tómala, pero cúidala mucho, y regresa rápido.", gcnew List<int>(gcnew array<int>{0,0,0}), 3));

    Dialogo^ d4 = gcnew Dialogo(gcnew List<String^>(gcnew array<String^>{
        L"KEVIN: Oh... está bien. Mi papá me dice que no debemos prestar las cosas importantes a",
        L"desconocidos. Pero, si te animas, puedes volver. Yo estoy aquí. Yo siempre estoy aquí."
    }), opciones4);

    List<Opcion^>^ opciones5 = gcnew List<Opcion^>();
    opciones5->Add(gcnew Opcion(L"¿Le 'pegaron' a Wilmer?", gcnew List<int>(gcnew array<int>{0,0,1}), 6));

    Dialogo^ d5 = gcnew Dialogo(gcnew List<String^>(gcnew array<String^>{
        L"[Kevin reproduce la grabación. La vista no es muy clara, pero se pueden distinguir si-",
        L"luetas evidentemente masculinas con ropas extrañamente similares a los hombres que  me",
        L"arrinconaron en la orilla. Se escuchan voces distorsionadas: 'el cargamento...  mañana",
        L"por la... quebrada Yonkiri... que nadie se entere...]",
        L"KEVIN: Ellos son los hombres malos, ¿verdad? Los que le pegaron a Wilmer... No les di-",
        L"gas que yo fui. Ellos piensan que solo soy un niño, que no entiende que pasa..."
    }), opciones5);

    Dialogo^ d6 = gcnew Dialogo(gcnew List<String^>(gcnew array<String^>{
        L"KEVIN: ¡Sí! Ocurrió el año pasado. Era cuando aún podíamos jugar y trabajar en la que-",
        L"brada Yonkiri. Mi papá estaba pescando, y yo me escabullí con mis amigos en las cerca-",
        L"nías.   Ahí fue cuando lo vimos... Wilmer y unos vecinos increparon a un hombre que se",
        L"veía raro. Él se fue, pero rapidito volvió con otros más. Y los golpearon con palos...",
        L"De allí se fueron. No entendí lo que pasaba. Pero no lo puedo olvidar..."
    }), 6, true);

    ArbolDialogo^ arbl0 = gcnew ArbolDialogo();
    arbl0->agregarDialogo(d0);
    arbl0->agregarDialogo(d1);
    arbl0->agregarDialogo(d2);
    arbl0->agregarDialogo(d3);
    arbl0->agregarDialogo(d4);
    arbl0->agregarDialogo(d5);
    arbl0->agregarDialogo(d6);

    EntidadEstatica^ kevin = gcnew EntidadEstatica(638, 430, gcnew Bitmap("sprites\\entidades\\kevin_idle.png"), arbl0);
    return kevin;
}

EntidadEstatica^ setupNINivel1Mapa2Rosa() {
    List<Opcion^>^ opciones0 = gcnew List<Opcion^>();
    opciones0->Add(gcnew Opcion(L"[Asentir con la cabeza y ayudarla]", gcnew List<int>(gcnew array<int>{5,10,0}), 1));
    opciones0->Add(gcnew Opcion(L"¿Qué...?", gcnew List<int>(gcnew array<int>{0,0,0}), 2));

    List<Opcion^>^ opciones0_1 = gcnew List<Opcion^>();
    opciones0_1->Add(gcnew Opcion(L"[Asentir con la cabeza y ayudarla]", gcnew List<int>(gcnew array<int>{5,10,0}), 1));

    Dialogo^ d0 = gcnew Dialogo(
        gcnew List<String^>(gcnew array<String^>{
            L"[Doña Rosa.  Está forcejeando con un cesto  evidentemente pesado de lo que  parece ser",
            L"|yuca. Para. Te observa. Apunta el cesto, luego una casa al otro lado del pueblo]",
            L"DONA ROSA: Hijo mío,  necesito llevar estas yucas hacia mi cabaña.  ¿Podrías ayudarme?",
            L"Mi cuerpo ya no estan fuerte como era antes.  Así de inclemente es el paso del tiempo."
        }), opciones0, false);

    Dialogo^ d1 = gcnew Dialogo(
        gcnew List<String^>(gcnew array<String^>{
            L"[Tomo el cesto.  Es más pesado de lo que parece,  y el inclemente calor matutino no es",
            L"de gran ayuda ante tanto esfuerzo físico. Ella va al lado mío. Por un momento, descan-",
            L"so,  y la observo.  Puedo ver una sonrisa esbozada en su rostro.  Los demás pobladores",
            L"me miran con gestos curiosos, algunos abiertamente anodados. ¿Es esto una prueba?]",
            L"                             [Presione E para continuar]                              "
        }), 3, true);

    Dialogo^ d2 = gcnew Dialogo(
        gcnew List<String^>(gcnew array<String^>{
            L"[¿Cómo puede que el forastero la entienda? Vuelve a hacer los gestos, esta vez más ob-",
            L"vios. Apunta agarra el cesto de yucas, intenta levantarlo, pero es muy pesado.]",
            L"DOÑA ROSA: Yucas... Llevar... Casa..."
        }), opciones0_1);

    Dialogo^ d3 = gcnew Dialogo(
        gcnew List<String^>(gcnew array<String^>{
            L"DONA ROSA: Gracias, hijo. Sé que no eres de aquí, y que no entiendes lo que hablo.  No",
            L"hay problema. Yo te enseñaré...",
            L"[La anciana entra a su cabaña y saca algunos objetos del día al día,  y empieza a nom-",
            L"|brarlos. Luego, apunta al horizonte y empieza a categorizar.  Agua.  Bosque.  Planta.",
            L"|Niño. Aldea... Luego empieza a actuar. Camina. Hace como que prepara. Como que habla]"
        }), 3, false);

    ArbolDialogo^ arbl0 = gcnew ArbolDialogo();
    arbl0->agregarDialogo(d0);
    arbl0->agregarDialogo(d1);
    arbl0->agregarDialogo(d2);
    arbl0->agregarDialogo(d3);

    EntidadEstatica^ rosa = gcnew EntidadEstatica(685, 220, gcnew Bitmap("sprites\\entidades\\rosa_idle.png"), arbl0);
    return rosa;
}

EntidadEstatica^ setupNINivel1Mapa2Tomas() {
    List<Opcion^>^ opciones0 = gcnew List<Opcion^>();
    opciones0->Add(gcnew Opcion(L"[Sentarse a su lado, manteniendo silencio]", gcnew List<int>(gcnew array<int>{2,2,0}), 1));
    opciones0->Add(gcnew Opcion(L"Buenos días, Abuelo... ¿Qué es lo que observa?", gcnew List<int>(gcnew array<int>{0,0,0}), 2));

    Dialogo^ d0 = gcnew Dialogo(gcnew List<String^>(gcnew array<String^>{
        L"[El anciano descansa en la hierba, bajo el umbral de un árbol. Mira fijamente al hori-",
        L"zonte,  como si  estuviese esperando  algo.  ¿A qué?...  Eso tengo que averiguarlo...]"
    }), opciones0);

    List<Opcion^>^ opciones1 = gcnew List<Opcion^>();
    opciones1->Add(gcnew Opcion(L"[Tomar el tabaco y fumarlo a su lado]", gcnew List<int>(gcnew array<int>{3,3,3}), 3));
    opciones1->Add(gcnew Opcion(L"¿Qué es lo que observas, Abuelo?", gcnew List<int>(gcnew array<int>{0,0,0}), 2));

    Dialogo^ d1 = gcnew Dialogo(gcnew List<String^>(gcnew array<String^>{
        L"[Me siento junto al anciano. Él no se mueve, ni gira la cabeza para mirarme.   Pasa el",
        L"tiempo. El silencio se vuelve espeso, luego cómo. Oigo el canto de la selva, expresado",
        L"en sus animales, en el fluir del agua, en la brisa soplando contra la vegetación]",
        L"[De pronto, el anciano saca  una  bolsa de tabaco seco.  Lo enciende.  Y me lo ofrece]",
        L"DON TOMAS: Sheri. Para el silencio. El silencio es la primera ñaantsi."
    }), opciones1);

    Dialogo^ d2 = gcnew Dialogo(gcnew List<String^>(gcnew array<String^>{
        L"[El anciano gira la  cabeza  por  un  momento y me observa con un gesto de curiosidad]",
        L"DON TOMAS: Ah... español. Extraño timpinare, ¿Qué buscas? ¿Ruido? Los extraños siempre",
        L"hacen ruido, y nada más.",
        L"[Niega con la cabeza y vuelve  a mirar al  horizonte.  Las palabras no son bienvenidas",
        L"aquí]"
    }));

    Dialogo^ d3 = gcnew Dialogo(gcnew List<String^>(gcnew array<String^>{
        L"[Tomo el tabaco, y con ayuda del encendedor que guardo en los bolsillos, empiezo a fu-",
        L"marlo. Puff... Es bienvenido en este extraño contexto. El anciano parece comprender mi",
        L"peculiar actitud]",
        L"DON TOMAS: Mis ojos ya no ven como antes.   Pero mis ojos de adentro... esos ven mejor",
        L"que antes.  Veo a mis ancestros navegando...  Veo sus rostros.  Y  siento  sus  almas.",
        L"                              [Presione E para continuar]                             "
    }), 4, true);

    Dialogo^ d4 = gcnew Dialogo(gcnew List<String^>(gcnew array<String^>{
        L"DON TOMAS: No sé leer palabras, pero sé leer a la naturaleza. Leo a las estrellas. Leo",
        L"al río, y a los árboles, y ellos me dicen que están sufriendo. Es por esos hombres que",
        L"han llegado y nos han robado nuestras tierras.  La madre Kipatsi llora, y oigo sus la-",
        L"mentos. Fue en la quebrada Yonkiri donde todo empezó. Nos amenazaron. Nos golpearon. Y",
        L"cuando intentamos defendernos, ellos trajeron más extraños que clamaban tener una 'de-",
        L"nuncia'. Puedes verlo por ti mismo. El río, y la tierra, al borde de la muerte..."
    }), 4, true);

    ArbolDialogo^ arbl0 = gcnew ArbolDialogo();
    arbl0->agregarDialogo(d0);
    arbl0->agregarDialogo(d1);
    arbl0->agregarDialogo(d2);
    arbl0->agregarDialogo(d3);
    arbl0->agregarDialogo(d4);

    EntidadEstatica^ tomas = gcnew EntidadEstatica(350, 365, gcnew Bitmap("sprites\\entidades\\tomas_idle.png"), arbl0);
    return tomas;
}

EntidadEstatica^ setupNINivel1Mapa3Elena() {
    List<Opcion^>^ opciones0 = gcnew List<Opcion^>();
    opciones0->Add(gcnew Opcion(L"Soy periodista. De Crónica Viva. ¿Es usted la maestra?", gcnew List<int>(gcnew array<int>{2,0,0}), 1));
    opciones0->Add(gcnew Opcion(L"¿Dos forasteros? ¿En seis meses?", gcnew List<int>(gcnew array<int>{2,0,0}), 2));

    Dialogo^ d0 = gcnew Dialogo(gcnew List<String^>(gcnew array<String^>{
        L"[A las afueras de lo que  parece ser una escuela,  hay una mujer de aspecto peculiar.",
        L"Foránea. Evidentemente, no es de la aldea. Está observando la escuela a través de las",
        L"ventanas, esperando a que los niños lleguen. Es la maestra.  Al verte, gira la cabeza",
        L"y sonríe con sorpresa]",
        L"ELENA: ¿Otro forastero? ¡Dos en seis meses! Esto es un récord."
    }), opciones0);

    List<Opcion^>^ opciones1 = gcnew List<Opcion^>();
    opciones1->Add(gcnew Opcion(L"¿La historia es diferente? Cuéntame más [MIN 25 DE CONFIANZA]", gcnew List<int>(gcnew array<int>{2,2,0}), 3, 30));

    Dialogo^ d1 = gcnew Dialogo(gcnew List<String^>(gcnew array<String^>{
        L"ELENA: Elena  Cárdenas.  Oficialmente,  'docente bilingüe  interina'.  Oficiosamente,",
        L"'la loca que se vino a la selva'...  ¿Y con que periodista, eh?   ¿Y de Crónica Viva?",
        L"Recuerdo haber leído algunos reportajes. Muy bien hechos, la verdad.  Pero... aquí la",
        L"historia es diferente. Aunque me sorprende que se hayan tomado la molestia en  enviar",
        L"a alguien..."
    }), opciones1);

    Dialogo^ d2 = gcnew Dialogo(gcnew List<String^>(gcnew array<String^>{
        L"ELENA: ¿Dos forasteros? Uno es usted.  Y el otro soy yo. Jaja... llegué en marzo. Pa-",
        L"rece poco, pero aquí cada día es... intenso.    Dígame, ¿Ya lo trataron mal? No se lo",
        L"tome a personal, aquí tratan mal a todo el mund al principio.      Es el protocolo de",
        L"bienvenida.    Aunque, sinceramente, no se los puedo reprochar, viendo todo lo que ha",
        L"pasado recientemente..."
    }), opciones1);

    List<Opcion^>^ opciones2 = gcnew List<Opcion^>();
    opciones2->Add(gcnew Opcion(L"¿Desertaron? ¿Para ir a trabajar?", gcnew List<int>(gcnew array<int>{5,8,0}), 4));

    Dialogo^ d3 = gcnew Dialogo(gcnew List<String^>(gcnew array<String^>{
        L"ELENA: Mire, le cuento un poco de mi historia. Llegué aquí para un programa piloto de",
        L"educación bilingüe.    Castellano y asháninka.     Los niños aprenden en dos idiomas.",
        L"Pero en seis meses, he presenciado en primera fila la realidad del pueblo.  Un salón,",
        L"por lo general, tiene quince alumnos. Quince. En una comunidad de ciento veinte fami-",
        L"lias. Antes, me cuentan, el promedio era treinta. ¿Sabe dónde están los otros?"
    }), opciones2);

    Dialogo^ d4 = gcnew Dialogo(gcnew List<String^>(gcnew array<String^>{
        L"ELENA: Los más grandes, en las talas.  Les pagan diez soles al día por cargar troncos",
        L"o talar árboles. Diez soles al día. Trescientos al mes si trabajan todos los días.   ",
        L"Los más chicos no se escapan. Ayudan en la chacra o en la pesca, pues tienen que ayu-",
        L"dar a sus padres, pues las ganancias ya no son como antes.   O simplemente, están en-",
        L"fermos. Vómitos. Diarrea. El agua de río está podrida y nadie hace nada. Y los demás,",
        L"emigraron. A donde sea. Pues aquí ya no hay futuro...                                ",
        L"                             [Presione E para continuar]                             "
    }), 5, true);

    Dialogo^ d5 = gcnew Dialogo(gcnew List<String^>(gcnew array<String^>{
        L"ELENA: Mire, le voy a dar algo que espero que le sea útil. Es mi diario de estos seis",
        L"meses. Sí, fui tan intrépida como para jugar a ser periodista cuando solamente soy u-",
        L"na maestra... ¿pero que más pude haber hecho? Hay notas, fotos, nombres, reportes es-",
        L"critos. Puse todo lo que oía, lo que averiguaba.  Quizás no sea mucho.  Quizás no sea",
        L"suficiente, pero es algo. Y usted tiene un millón de chances más que yo de hacer algo",
        L"que de verdad cambie el rumbo de este pueblo."
    }), 5, true);

    ArbolDialogo^ arbl0 = gcnew ArbolDialogo();
    arbl0->agregarDialogo(d0);
    arbl0->agregarDialogo(d1);
    arbl0->agregarDialogo(d2);
    arbl0->agregarDialogo(d3);
    arbl0->agregarDialogo(d4);
    arbl0->agregarDialogo(d5);

    EntidadEstatica^ elena = gcnew EntidadEstatica(395, 237, gcnew Bitmap("sprites\\entidades\\elena_idle.png"), arbl0);
    return elena;
}

EntidadEstatica^ setupNINivel1Mapa3Silvia() {
    List<Opcion^>^ opciones0 = gcnew List<Opcion^>();
    opciones0->Add(gcnew Opcion(L"¿Le diste agua de río? [MIN. CON. LENGUA: 15]", gcnew List<int>(gcnew array<int>{0,5,0}), 1, 5, 15, false));
    opciones0->Add(gcnew Opcion(L"Tu hijo está enfermo. ¿Puedo verlo? [MIN. CON. LENGUA: 10]", gcnew List<int>(gcnew array<int>{2,5,5}), 2, 5, 10, false));
    opciones0->Add(gcnew Opcion(L"Eh...", gcnew List<int>(gcnew array<int>{0,0,0}), 0));

    Dialogo^ d0 = gcnew Dialogo(gcnew List<String^>(gcnew array<String^>{
        L"[Una mujer, joven, descansa posada contra la pared de una cabaña. Tiene una expresión",
        L"|perdida.  Está cargando a un bebé evidentemente enfermo en brazos.    Al verte, mira",
        L"|con desconfianza, pero el llanto del bebé puede más. Habla atropelladamente.]",
        L"SILVIA: Mi hijo está enfermo... por beber esa agua enferma del río..."
    }), opciones0, false);

    List<Opcion^>^ opciones1 = gcnew List<Opcion^>();
    opciones1->Add(gcnew Opcion(L"Prometo buscar ayuda", gcnew List<int>(gcnew array<int>{6,3,5}), 3));
    opciones1->Add(gcnew Opcion(L"Llévaselo a la profesora Elena. Y no vuelvas a darle agua del río...", gcnew List<int>(gcnew array<int>{1,3,3}), 4));

    Dialogo^ d1 = gcnew Dialogo(gcnew List<String^>(gcnew array<String^>{
        L"[Asiente, con lágrimas en los ojos. El bebé toce débilmente, como un maullido]",
        L"SILVIA:Sí... no había otra.  La lluvia no viene. El pozo estaba seco. Solo ha-",
        L"bía el río... Y el río está enfermo. Enfermo... Mamá CLARA le dió hierbas. Pe-",
        L"ro no es suficiente. Necesita la POSTA. Pero está lejos, muy lejos..."
    }), opciones1, false);

    Dialogo^ d2 = gcnew Dialogo(gcnew List<String^>(gcnew array<String^>{
        L"[Silvia duda. Pero tras un momento de reflexión, asiente, y me entrega al bebé.  Pue-",
        L"do ver su cuerpecito de cerca: en su piel hay un sarpullido rojizo.    Sus ojos están",
        L"hundidos. Respira con dificultad.]",
        L"SILVIA: Nija... Katsimari nija..."
    }));

    Dialogo^ d3 = gcnew Dialogo(gcnew List<String^>(gcnew array<String^>{
        L"[Su mirada es una mezcla extraña de esperanza y entrenado escepticismo]",
        L"SILVIA: No... Eso dijeron los demás. Todos prometen ayudar y nadie hace nada. Pero...",
        L"vi que ayudaste a los demás. Creeré que eres diferente. Espero no equivocarme..."
    }), 3, false);

    Dialogo^ d4 = gcnew Dialogo(gcnew List<String^>(gcnew array<String^>{
        L"[Silvia niega con la cabeza, y mese al bebé en brazos]",
        L"SILVIA: No, Elena ya vino.   Me dio pastillas para el bebé.   Pero la diarrea vuelve.",
        L"Siempre vuelve. Mientras el agua esté mala, el bebé estará malo..."
    }), 4, false);

    ArbolDialogo^ arbl0 = gcnew ArbolDialogo();
    arbl0->agregarDialogo(d0);
    arbl0->agregarDialogo(d1);
    arbl0->agregarDialogo(d2);
    arbl0->agregarDialogo(d3);
    arbl0->agregarDialogo(d4);

    EntidadEstatica^ silvia = gcnew EntidadEstatica(720, 219, gcnew Bitmap("sprites\\entidades\\silvia_idle.png"), arbl0);
    return silvia;
}

EntidadEstatica^ setupNINivel1Mapa3Clara() {
    List<Opcion^>^ opciones0 = gcnew List<Opcion^>();
    opciones0->Add(gcnew Opcion(L"Buenos días, ¿Es usted la curandera del pueblo?", gcnew List<int>(gcnew array<int>{0,0,0}), 1));

    List<Opcion^>^ opciones1 = gcnew List<Opcion^>();
    opciones1->Add(gcnew Opcion(L"Curandera. Es la palabra más adecuada.", gcnew List<int>(gcnew array<int>{7,0,7}), 2));
    opciones1->Add(gcnew Opcion(L"¿Mamá Clara? Si no me equivoco, así la llaman en el pueblo", gcnew List<int>(gcnew array<int>{4,0,7}), 3));
    opciones1->Add(gcnew Opcion(L"No lo sé. No la conozco bien.", gcnew List<int>(gcnew array<int>{5,0,7}), 4));

    Dialogo^ d0 = gcnew Dialogo(gcnew List<String^>(gcnew array<String^>{
        L"[Mamá Clara está moliendo hojas secas en un mortero de piedra.   El aire alrededor de",
        L"su casa huele a hojas secas y a humo dulce.    Al verme, deja el mortero y levanta la",
        L"cabeza con ojos  pequeños  pero  increíblemente  agudos.  No dice nada. Solo espera]"
    }), opciones0);

    Dialogo^ d1 = gcnew Dialogo(gcnew List<String^>(gcnew array<String^>{
        L"MAMÁ CLARA: Curandera. Bruja. Vieja. Así me llaman.  ¿Cómo me llamarás tú, fo-",
        L"rastero? [Me escruta con la mirada. No es una pregunta retórica]"
    }), opciones1);

    Dialogo^ d2 = gcnew Dialogo(gcnew List<String^>(gcnew array<String^>{
        L"MAMÁ CLARA: Curandera...  Buena palabra.  Es la más justa.   Mi hermana Rosa dijo que",
        L"eras trabajadores, y no un 'periodista' más. Ven, siéntate. Tengo algo para ti.",
        L"                             [Presione E para continuar]                             "
    }), 5, true);

    Dialogo^ d3 = gcnew Dialogo(gcnew List<String^>(gcnew array<String^>{
        L"MAMÁ CLARA: Mamá Clara... así me llaman los que me respetan.  ¿Tú me respetas, perio-",
        L"dista? ¿O tan sólo buscas 'información'?     [La última palabra lo dice con sarcasmo]",
        L"                             [Presione E para continuar]                             "
    }), 5, true);

    Dialogo^ d4 = gcnew Dialogo(gcnew List<String^>(gcnew array<String^>{
        L"MAMÁ CLARA: No lo sabes... Honesto. Eso es raro para los de tu tipo. A la mayoría les",
        L"da miedo decir 'no sé' y tienen que fingir conocerlo todo. Anda, siéntate, no muerdo,",
        L"solo curo.",
        L"                             [Presione E para continuar]                             "
    }), 5, true);

    Dialogo^ d5 = gcnew Dialogo(gcnew List<String^>(gcnew array<String^>{
        L"MAMÁ CLARA: Las plantas tienen alma.  La naturaleza, en sí, es un todo.   Nosotros no",
        L"somos superiores a los animales, o a las plantas. Dependemos de ellas. Y ellas depen-",
        L"den de nosotros. Nuestro pueblo nació de la comunión del hombre con la tierra, Kipat-",
        L"si. Cuando cosechamos, o pescamos, le pedimos permiso a la tierra. Cuando alguien en-",
        L"enferma, le pedimos permiso para que nos cure. Esto es así. Y por siglos, siempre  ha",
        L"sido así... hasta que, recientemente, algo muy grave cambió...",
        L"                             [Presione E para continuar]                             "
    }), 6, true);

    Dialogo^ d6 = gcnew Dialogo(gcnew List<String^>(gcnew array<String^>{
        L"MAMÁ CLARA: Los hombres del monte, a los que les llamamos 'Los Mudo',  llegaro en ca-",
        L"ravanas y grandes botes. Se establecieron cerca a la Quebrada Yonkiri, nuestro puerto",
        L"pesquero por décadas. Y en solo meses... el río lloraba de dolor. Los peces aparecían",
        L"panza arriba, y colores extraños flotaban como espuma. Y nuestros niños se enfermaban",
        L"por doquier. Yo lo sé, por que yo era los que los trataba.   Pero, ante tanta maldad,",
        L"las plantas no eran suficientes, y muchos de ellos murieron...",
        L"                             [Presione E para continuar]                             "
    }), 7, true);

    Dialogo^ d7 = gcnew Dialogo(gcnew List<String^>(gcnew array<String^>{
        L"MAMÁ CLARA: Ten, periodista, este registro.    Elena lo hizo, pues yo no sé escribir.",
        L"Están todos los nombres de los que murieron, junto a sus datos, y sus fotos.   Perio-",
        L"dista, si de verdad dices ser diferente, oye el llamado de la naturaleza. Kipatsi es-",
        L"tá furiosa ante tan salvaje agresión, y quizás, ante nuestra inacción."
    }), 7, true);

    ArbolDialogo^ arbl0 = gcnew ArbolDialogo();
    arbl0->agregarDialogo(d0);
    arbl0->agregarDialogo(d1);
    arbl0->agregarDialogo(d2);
    arbl0->agregarDialogo(d3);
    arbl0->agregarDialogo(d4);
    arbl0->agregarDialogo(d5);
    arbl0->agregarDialogo(d6);
    arbl0->agregarDialogo(d7);

    EntidadEstatica^ clara = gcnew EntidadEstatica(755, 420, gcnew Bitmap("sprites\\entidades\\clara_idle.png"), arbl0);
    return clara;
}

EntidadEstatica^ setupNINivel1Mapa4Maza() {
    List<Opcion^>^ opciones0 = gcnew List<Opcion^>();
    opciones0->Add(gcnew Opcion(L"Sí, soy periodista. ¿A poco a que me estabas esperando, eh?", gcnew List<int>(gcnew array<int>{0,0,0}), 1));
    opciones0->Add(gcnew Opcion(L"No tengo por qué decirte quien soy", gcnew List<int>(gcnew array<int>{0,0,0}), 2));

    Dialogo^ d0 = gcnew Dialogo(gcnew List<String^>(gcnew array<String^>{
        L"[Don Maza está organizando su mercancía, volviéndola a ordenar por enémisa vez la ho-",
        L"ra. Sin embargo, al levantar la mirada, logra observarme, y abre ambos brazos]",
        L"MAZA: ¡Eh, forastero! ¿Otro de ustedes?  ¡Este lugar se está volviendo un centro tu-",
        L"rístico! Pero vamos, ¿Quién eres? No serás de la ONG, ¿no?    No... eres periodista.",
        L"Sí, lo eres. ¿Le atiné, eh?"
    }), opciones0);

    Dialogo^ d1 = gcnew Dialogo(gcnew List<String^>(gcnew array<String^>{
        L"MAZA: ¡Y quizás que sí! Obviamente, no eres de una ONG.   Ellos vienen con chalecos,",
        L"botas nuevas y balsas llenas de comida que se agotan en dos semanas.   En cambio, tu",
        L"vienes con la ropa arrugada y con una cara ...    ¡Cómo si hubieses visto al diablo!",
        L"Además, un pajarito me contó que venías. No es un secreto, en realidad.  Los del mu-",
        L"elle no saben guardar secretos.",
        L"                             [Presione E para continuar]                             "
    }), 3, true);

    Dialogo^ d2 = gcnew Dialogo(gcnew List<String^>(gcnew array<String^>{
        L"MAZA: ¿Un poco serio, periodista? No, lo siento, pero no hace falta que pregunte. Tu",
        L"apariencia no engaña ni a un infante. Y pues, ¿Quién más podría ser?  Los forasteros",
        L"que no traen algún tipo de bien consigo son extremadamente raros. Los que vienen son",
        L"comerciantes. Buscan un dinero extra. Y tú... tú también vienes en búsqueda de algo.",
        L"Quizás no de dinero, pero de información. Así es cómo funciona el mundo.",
        L"                             [Presione E para continuar]                             "
    }), 5, true);

    List<Opcion^>^ opciones1 = gcnew List<Opcion^>();
    opciones1->Add(gcnew Opcion(L"¿Quieres que te pague para que hables? Va. Así es como funciona el mundo real.", gcnew List<int>(gcnew array<int>{-3,0,5}), 4));
    opciones1->Add(gcnew Opcion(L"¿Un incentivo? Lo siento, no he caído tan bajo como para dar sobornos.", gcnew List<int>(gcnew array<int>{3,0,0}), 5));

    Dialogo^ d3 = gcnew Dialogo(gcnew List<String^>(gcnew array<String^>{
        L"MAZA: Ven, ven, acércate, no tengas miedo... [Susurrando] Soy zorro viejo, y he reco-",
        L"rrido este río por más de veinte años.   ¡Y nunca rechazo una buena chela con alguien",
        L"más! Por eso, conozco cosas. Mucho más de las que Wilmer y Evaristo saben.  Ellos mi-",
        L"ran al pueblo, y yo miro el río. Y en el río pasan cosas de noche. Mira, voy al grano",
        L"Un incentivo no vendría mal.  Yo busco mi ganancia.  Tú información.   Ambos ganamos."
    }), opciones1);

    Dialogo^ d4 = gcnew Dialogo(gcnew List<String^>(gcnew array<String^>{
        L"MAZA: ¡Ahora sí hablamos! 50 soles. Es barato para todo lo que vas a conseguir.",
        L"Dato uno: Los madereros se mueven de noche. Entres las doce y las tres. Es cuando pa-",
        L"san la madera —y otras mercancías— río abajo.",
        L"Dato dos: Hay un tipo en la quebrada. No es maderero. Es químico.  Mezcla cosas. Pre-",
        L"aquellos extraños bidones que entierran.",
        L"Dato tres: La próxima semana, llega un cargamento. Todos están nerviosos. Incluso los",
        L"Mudo. ¿Qué es? No lo sé. ¡Y mejor que sea así!"
    }), 4, true);

    Dialogo^ d5 = gcnew Dialogo(gcnew List<String^>(gcnew array<String^>{
        L"MAZA: Ah... siempre tan aguafiestas, periodista. ¿Mateo López, no? Leí algunos de tus",
        L"artículos. Son... interesantes. Pero siento que les falta un poco de sazón.  Un sabor",
        L"de la susodicha 'verdad' que tanto defiendas, que te impulsaría a la fama y  le daría",
        L"un empujoncito al pueblo.  ¡Pero no me sorprende que le falte tanta sazón si eres tan",
        L"aburrido y puritano! No hay problema. Tendrás que conseguir información a la antigua,",
        L"preguntando. Y ya sabes como funciona eso aquí."
    }), 5, true);

    ArbolDialogo^ arbl0 = gcnew ArbolDialogo();
    arbl0->agregarDialogo(d0);
    arbl0->agregarDialogo(d1);
    arbl0->agregarDialogo(d2);
    arbl0->agregarDialogo(d3);
    arbl0->agregarDialogo(d4);
    arbl0->agregarDialogo(d5);

    EntidadEstatica^ maza = gcnew EntidadEstatica(202, 231, gcnew Bitmap("sprites\\entidades\\maza_idle.png"), arbl0);
    return maza;
}

EntidadEstatica^ setupNINivel1Mapa4Jeremias() {
    List<Opcion^>^ opciones0 = gcnew List<Opcion^>();
    opciones0->Add(gcnew Opcion(L"Sí, soy de fiar.", gcnew List<int>(gcnew array<int>{1,0,0}), 1));
    opciones0->Add(gcnew Opcion(L"Eso espero.", gcnew List<int>(gcnew array<int>{0,0,0}), 1));

    Dialogo^ d0 = gcnew Dialogo(gcnew List<String^>(gcnew array<String^>{
        L"[Jeremías está cortando los tablones que, por lo que parece, se utilizarán para cons",
        L"truir un bote. Parece tener experiencia con la madera. Al acercarme, se paraliza,  y",
        L"deja de hacer lo que está haciendo. Duda por un momento. Luego se acerca]",
        L"JEREMIAS: Ey, periodista.   ¿Eres alguien de fiar? Wilmer dijo que probablemente sí."
    }), opciones0);

    List<Opcion^>^ opciones1 = gcnew List<Opcion^>();
    opciones1->Add(gcnew Opcion(L"Cuéntamelo. Estás en discresión conmigo.", gcnew List<int>(gcnew array<int>{3,0,6}), 2));
    opciones1->Add(gcnew Opcion(L"¿Por qué me lo dices a mí, el forastero, y no a tu comunidad?", gcnew List<int>(gcnew array<int>{0,0,6}), 3));

    Dialogo^ d1 = gcnew Dialogo(gcnew List<String^>(gcnew array<String^>{
        L"JEREMIAS: Espero que sí. Por que si no, estoy muerto.  Mira, yo trabajo para los ma-",
        L"dereros. Allá en la quebrada, ocasionalmente. No me gusta.  Pero mi hermana está en-",
        L"ferma y mi mamá no puede trabajar. Y yo tengo que ayudar en casa, sea como sea.",
        L"Pero... hay cosas que ellos hacen que no están bien.  Cosas que ni siquiera Wilmer o",
        L"cualquiera del pueblo saben."
    }), opciones1);

    Dialogo^ d2 = gcnew Dialogo(gcnew List<String^>(gcnew array<String^>{
        L"JEREMIAS: Tienen bidones enterrados por la quebrada.    No solo trabajan con madera.",
        L"Es de un negocio 'extra' del que todos hablan pero que solo los altos rangos conocen",
        L"los detalles. También tienen químicos. No sé que son, pero son peligrosos. Un traba-",
        L"jador abrió unos y se quemó las manos.   Estos están en un claro, detrás de la ceiba",
        L"caída. Si vas, ten cuidado. Hay un tipo al que le llaman 'El Químico'. Él es diferen",
        L"te a los demás. Es malo. Muy malo."
    }), 2, true);

    Dialogo^ d3 = gcnew Dialogo(gcnew List<String^>(gcnew array<String^>{
        L"JEREMIAS: Porque no tengo el coraje para hacerlo. No sabes de la vergüenza que me cau",
        L"sa tener que estar allí cada maldito día, sabiendo lo que sé. Y aunque pudiera, no se",
        L"lo diría a nadie. Si se lo digo a Wilmer, él actuará. Y lo van a matar.   La otra vez",
        L"pegaron, y si no fuese por la intervención de Evaristo y los vecinos, lo hubiesen ma-",
        L"tado. En cambio, tú... tú puedes hacer un gran cambio.  Exponerlos.  Y ni aunque ame-",
        L"dranten a medio mundo se saldrán con la suya."
    }), 2, true);

    ArbolDialogo^ arbl0 = gcnew ArbolDialogo();
    arbl0->agregarDialogo(d0);
    arbl0->agregarDialogo(d1);
    arbl0->agregarDialogo(d2);
    arbl0->agregarDialogo(d3);

    EntidadEstatica^ jeremias = gcnew EntidadEstatica(577, 188, gcnew Bitmap("sprites\\entidades\\jeremias_idle.png"), arbl0);
    return jeremias;
}

EntidadEstatica^ setupNINivel1Mapa4Timoteo() {
    List<Opcion^>^ opciones0 = gcnew List<Opcion^>();
    opciones0->Add(gcnew Opcion(L"¿Qué es lo que le pasa al río?", gcnew List<int>(gcnew array<int>{3,1,5}), 1));
    opciones0->Add(gcnew Opcion(L"¿Es por esas manchas brillantes y espumosas?", gcnew List<int>(gcnew array<int>{5,1,5}), 2));

    Dialogo^ d0 = gcnew Dialogo(gcnew List<String^>(gcnew array<String^>{
        L"[Timoteo, un hombre mayor, de  quizás  más  de 70 años, descansa cerca de la orilla,",
        L"con su caña de pescar en manos.  Cuando me acerco, no se voltea, pero un sutil movi-",
        L"miento en su espalda muestra que me ha oído llegar. Habla sin voltearse]",
        L"TIMOTEO: ¿Sabes cuántos peces saqué hoy? Ninguno. Ayer, nada. La semana pasada, solo",
        L"uno. Chiquito. Este río era mi despensa. Ahora se volvió mi cementerio."
    }), opciones0);

    Dialogo^ d1 = gcnew Dialogo(gcnew List<String^>(gcnew array<String^>{
        L"TIMOTEO: Lo han envenenado. Allá, en la quebrada Yonkiri, donde antes nosotros pes-",
        L"cábamos y teníamos nuestras cabañas.   Ahora que no estamos, han levantado laborato-",
        L"rios. No sé que hacen, pero todos sus desechos los tiran al río.  Antes se podía be-",
        L"ber directamente de él. Ahora... mira [Saca un tubo con un líquido espumoso y amari-",
        L"llento. El olor es horrible. Logro distinguir lo que parece ser el olor a gasolina]",
        L"                             [Presione E para continuar]                             "
    }), 3, true);

    Dialogo^ d2 = gcnew Dialogo(gcnew List<String^>(gcnew array<String^>{
        L"TIMOTEO: Las viste bien.    La mayoría de forasteros no se contentan con mirar, solo",
        L"con preguntar. Esas manchas son ácido, quizás gasolina, o algo peor.  Los peces flo-",
        L"tan panza arriba. Y todo aquel que bebe ese agua, así la hierva, está en riesgo. De-",
        L"cenas de niños han enfermado por ello. E incluso, algunos murieron. Mis nietos ya no",
        L"comen peces del río. Tienen miedo.",
        L"                             [Presione E para continuar]                             "
    }), 3, true);

    Dialogo^ d3 = gcnew Dialogo(gcnew List<String^>(gcnew array<String^>{
        L"TIMOTEO: Mis bisabuelos llegaron aquí, huyendo de los caucheros. La naturaleza los a-",
        L"cobijo. Y el chamán les dijo: 'Aquí. Esta tierra es kametsa'.  Kametsa significa buen",
        L"vivir. Y así era antes. Nosotros protegíamos a la naturaleza, y ella nos recompensaba",
        L"dándonos cobijo y alimento. Pero eso era antes. Le hemos fallado. Está agonizando.  Y",
        L"nosotros estamos agonizando junto a ella."
    }), 3, true);

    ArbolDialogo^ arbl0 = gcnew ArbolDialogo();
    arbl0->agregarDialogo(d0);
    arbl0->agregarDialogo(d1);
    arbl0->agregarDialogo(d2);
    arbl0->agregarDialogo(d3);

    EntidadEstatica^ timoteo = gcnew EntidadEstatica(722, 330, gcnew Bitmap("sprites\\entidades\\timoteo_idle.png"), arbl0);
    return timoteo;
}